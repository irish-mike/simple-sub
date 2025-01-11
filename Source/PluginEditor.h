#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "SimpleKnob.hpp"
#include "SimpleGrid.hpp"
#include "Square.hpp"
#include "ControlPanel.hpp"

// Editor for the audio processor
class SimpleSubAudioProcessorEditor : public juce::AudioProcessorEditor
{
public:
    SimpleSubAudioProcessorEditor(SimpleSubAudioProcessor&);
    ~SimpleSubAudioProcessorEditor() override = default;

    void paint(juce::Graphics&) override;
    void resized() override;

    void resizeWithAspect();

private:
    SimpleSubAudioProcessor& audioProcessor;

    ControlPanel controlPanel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SimpleSubAudioProcessorEditor)
};