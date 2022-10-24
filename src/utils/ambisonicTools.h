#pragma once
#include <juce_audio_basics/juce_audio_basics.h>

int isqrt(int x);

juce::String getOrderString(int order);

const std::array<float, 64> n3d2sn3d = {
  1.0000000000000000e+00f, 5.7735026918962584e-01f, 5.7735026918962584e-01f,
  5.7735026918962584e-01f, 4.4721359549995793e-01f, 4.4721359549995793e-01f,
  4.4721359549995793e-01f, 4.4721359549995793e-01f, 4.4721359549995793e-01f,
  3.7796447300922720e-01f, 3.7796447300922720e-01f, 3.7796447300922720e-01f,
  3.7796447300922720e-01f, 3.7796447300922720e-01f, 3.7796447300922720e-01f,
  3.7796447300922720e-01f, 3.3333333333333331e-01f, 3.3333333333333331e-01f,
  3.3333333333333331e-01f, 3.3333333333333331e-01f, 3.3333333333333331e-01f,
  3.3333333333333331e-01f, 3.3333333333333331e-01f, 3.3333333333333331e-01f,
  3.3333333333333331e-01f, 3.0151134457776363e-01f, 3.0151134457776363e-01f,
  3.0151134457776363e-01f, 3.0151134457776363e-01f, 3.0151134457776363e-01f,
  3.0151134457776363e-01f, 3.0151134457776363e-01f, 3.0151134457776363e-01f,
  3.0151134457776363e-01f, 3.0151134457776363e-01f, 3.0151134457776363e-01f,
  2.7735009811261457e-01f, 2.7735009811261457e-01f, 2.7735009811261457e-01f,
  2.7735009811261457e-01f, 2.7735009811261457e-01f, 2.7735009811261457e-01f,
  2.7735009811261457e-01f, 2.7735009811261457e-01f, 2.7735009811261457e-01f,
  2.7735009811261457e-01f, 2.7735009811261457e-01f, 2.7735009811261457e-01f,
  2.7735009811261457e-01f, 2.5819888974716110e-01f, 2.5819888974716110e-01f,
  2.5819888974716110e-01f, 2.5819888974716110e-01f, 2.5819888974716110e-01f,
  2.5819888974716110e-01f, 2.5819888974716110e-01f, 2.5819888974716110e-01f,
  2.5819888974716110e-01f, 2.5819888974716110e-01f, 2.5819888974716110e-01f,
  2.5819888974716110e-01f, 2.5819888974716110e-01f, 2.5819888974716110e-01f,
  2.5819888974716110e-01f,
};
