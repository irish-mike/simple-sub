#pragma once
#include <JuceHeader.h>
#include "SimpleKnob.hpp"
#include "SimpleFader.hpp"
#include "PluginProcessor.h"

class ControlPanel : public juce::Component
{
public:
    ControlPanel(SimpleSubAudioProcessor& processor);
   
    ~ControlPanel() override = default;

    void registerListeners();

    void paint(juce::Graphics& g) override;
    void resized() override;

    void setComponentGrid();

private:

    SimpleFader gainSlider{ "Gain", -60, 0, -12 };            // Volume: -60 dB (silent) to 0 dB (max). Default: -12 dB.
    SimpleFader lpFilterSlider{ "Filter", 20, 20000, 20000 }; // Cutoff frequency: 20 Hz to 20 kHz. Default: Fully open (20 kHz).
    SimpleKnob distortSlider{ "Distort", 0.0, 100.0, 0.0 };   // Distortion: 0% (clean) to 100% (max). Default: 0% (no distortion).
    SimpleKnob morphSlider{ "Morph", 0.0, 100.0, 0 };         // Morph: 0% (start) to 100% (end). Default: 0% (pure sine).
    SimpleKnob attackSlider{ "Attack", 0.001, 10.0, 0.1 };    // Attack time: 1 ms to 10 s. Default: 100 ms.
    SimpleKnob releaseSlider{ "Release", 0.001, 10.0, 0.5 };  // Release time: 1 ms to 10 s. Default: 500 ms.

    SimpleSubAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ControlPanel)
};