#pragma once
#include "SphericalVector.h"
#include <juce_audio_processors/juce_audio_processors.h>

class PluginState : public juce::AudioProcessorValueTreeState
{
public:
  explicit PluginState(juce::AudioProcessor&);

  juce::XmlElement getState();
  void setState(const juce::XmlElement&);

  SphericalVector vectorLeft() const;
  SphericalVector vectorRight() const;

  inline static const std::pair<int, int> orderRange{ 0, 5 };
};
