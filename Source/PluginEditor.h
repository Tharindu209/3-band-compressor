/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "GUI/LookAndFeel.h"
#include "GUI/GlobalControls.h"
#include "GUI/CompressorBandControls.h"
#include "GUI/UtilityComponents.h"

#include "GUI/SpectrumAnalyzer.h"
#include "GUI/CustomButtons.h"


struct ControlBar : juce::Component
{
    ControlBar();
    void resized() override;
    
    PowerButton globalBypassButton;
    AnalyzerButton analyzerButton;
};





/**
*/
class MyCompAudioProcessorEditor  : public juce::AudioProcessorEditor,
juce::Timer
{
public:
    MyCompAudioProcessorEditor (MyCompAudioProcessor&);
    ~MyCompAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

    void timerCallback() override;
private:
    LookAndFeel lnf;
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    MyCompAudioProcessor& audioProcessor;
    
    ControlBar controlBar;
    CompressorBandControls bandControls { audioProcessor.apvts };
    SpectrumAnalyzer analyzer { audioProcessor };
    GlobalControls globalControls { audioProcessor.apvts };
    
    void toggleGlobalBypassState();
    
    std::array<juce::AudioParameterBool*, 3> getBypassParams();
    
    void updateGlobalBypassButton();

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MyCompAudioProcessorEditor)
};
