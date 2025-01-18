#pragma once

#include <JuceHeader.h>
#include "SimpleSlider.hpp"


/**
 * A simple knob component that places a label at the top,
 * and a rotary slider (with a text box below) below the label.
 */
class SimpleKnob : public SimpleSlider
{
public:

    SimpleKnob(const juce::String& name, double minValue, double maxValue, double defaultValue)
        : SimpleSlider(name, minValue, maxValue, defaultValue)
    {
        setSliderStyle();
    }

    void setSliderStyle() override
    {
        slider.setSliderStyle(juce::Slider::Rotary);
        slider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50, 20);

        slider.setColour(juce::Slider::rotarySliderFillColourId, juce::Colours::darkgreen);
        slider.setColour(juce::Slider::rotarySliderOutlineColourId, juce::Colours::darkgrey);
        slider.setColour(juce::Slider::thumbColourId, juce::Colours::whitesmoke);

        label.setJustificationType(juce::Justification::centred);
        slider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50, 20);
    }
};
