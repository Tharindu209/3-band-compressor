/*
  ==============================================================================

    LookAndFeel.h
    Created: 1 JAN 2023
    Author:  DR MUSIC

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

#define USE_LIVE_CONSTANT false

#if USE_LIVE_CONSTANT
#define colorHelper(c) JUCE_LIVE_CONSTANT(c);
#else
#define colorHelper(c) c;
#endif

namespace ColorScheme
{
inline juce::Colour getGainReductionColor() { return colorHelper(juce::Colour(0xff0cf0af)); }
inline juce::Colour getInputSignalColor() { return colorHelper(juce::Colour(0xffff0000)); }
inline juce::Colour getOutputSignalColor() { return colorHelper(juce::Colour(0xffffffa1)); }
inline juce::Colour getSliderFillColor() { return colorHelper(juce::Colour(0xff7c7c7d)); }
inline juce::Colour getOrangeBorderColor() { return colorHelper(juce::Colour(0xff0734fa)); }
inline juce::Colour getSliderRangeTextColor() { return colorHelper(juce::Colour(0xffafaeeb));}
inline juce::Colour getSliderBorderColor() { return colorHelper(juce::Colour(0xfffeffc9));}
inline juce::Colour getThresholdColor() { return colorHelper(juce::Colour(0xff0c7de0)); }
inline juce::Colour getModuleBorderColor() { return colorHelper(juce::Colour(0xff68e3ba)); }
inline juce::Colour getTitleColor() { return colorHelper(juce::Colour(0xffe6f1f7)); }
inline juce::Colour getAnalyzerGridColor() { return colorHelper(juce::Colour(0xff262626)); }
inline juce::Colour getTickColor() { return colorHelper(juce::Colour(0xff4d1717)); }
inline juce::Colour getMeterLineColor() { return colorHelper(juce::Colour(0xff3c3c3c)); }
inline juce::Colour getScaleTextColor() { return juce::Colours::white; }

}


struct LookAndFeel : juce::LookAndFeel_V4
{
    void drawRotarySlider (juce::Graphics&,
                           int x, int y, int width, int height,
                           float sliderPosProportional,
                           float rotaryStartAngle,
                           float rotaryEndAngle,
                           juce::Slider&) override;
    
    void drawToggleButton (juce::Graphics &g,
                           juce::ToggleButton & toggleButton,
                           bool shouldDrawButtonAsHighlighted,
                           bool shouldDrawButtonAsDown) override;
};
