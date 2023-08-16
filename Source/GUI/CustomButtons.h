/*
  ==============================================================================

    CustomButtons.h
    Created: 1 JAN 2023
    Author:  DR MUSIC

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

struct PowerButton : juce::ToggleButton { };

struct AnalyzerButton : juce::ToggleButton
{
    void resized() override;
    
    juce::Path randomPath;
};
