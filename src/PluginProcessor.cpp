#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "SphericalHarmonics.h"
#include "SphericalVector.h"
#include <fmt/format.h>

using Coefficients = std::array<std::array<float, 36>, 2>;

namespace {
void populateOutputBuffer(juce::AudioBuffer<float>& buffer,
                          Coefficients oldCoeffs,
                          Coefficients newCoeffs,
                          size_t ambisonicOrder = 5)
{
  const auto bufferBackup = buffer;
  const auto numChannels = (ambisonicOrder + 1) * (ambisonicOrder + 1);

  if (numChannels > static_cast<size_t>(buffer.getNumChannels()))
    DBG(fmt::format(
      "WARNING: ambisonics order {} requires {} output channels, but only {} are available",
      ambisonicOrder,
      numChannels,
      buffer.getNumChannels()));

  for (auto ch = 0U; ch < numChannels; ++ch) {
    buffer.copyFromWithRamp(static_cast<int>(ch),
                            0,
                            bufferBackup.getReadPointer(0),
                            buffer.getNumSamples(),
                            oldCoeffs[0][ch],
                            newCoeffs[0][ch]);
    buffer.addFromWithRamp(static_cast<int>(ch),
                           0,
                           bufferBackup.getReadPointer(1),
                           buffer.getNumSamples(),
                           oldCoeffs[1][ch],
                           newCoeffs[1][ch]);
  }
}
} // namespace

PluginProcessor::PluginProcessor()
  : params(*this)
{
}

void PluginProcessor::processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer&)
{
  // const auto ambisonicOrder = params.getRawParameterValue("order");
  // assert(ambisonicOrder != nullptr);

  // const auto newCoefficients = std::array{
  //   harmonics(params.vectorLeft()),
  //   harmonics(params.vectorRight()),
  // };

  // populateOutputBuffer(
  //   buffer, oldCoefficients, newCoefficients, static_cast<size_t>(*ambisonicOrder));
  // oldCoefficients = newCoefficients;
}

juce::AudioProcessorEditor* PluginProcessor::createEditor()
{
  return new PluginEditor(*this, params);
}

void PluginProcessor::getStateInformation(juce::MemoryBlock& destData)
{
  copyXmlToBinary(params.getState(), destData);
}

void PluginProcessor::setStateInformation(const void* data, int sizeInBytes)
{
  if (const auto xml = getXmlFromBinary(data, sizeInBytes))
    params.setState(*xml);
}
