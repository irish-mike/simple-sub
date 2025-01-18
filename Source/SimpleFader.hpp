#pragma once

#include <JuceHeader.h>
#include "SimpleSlider.hpp"

class SimpleFader : public SimpleSlider
{
public:
    SimpleFader(const juce::String& name, double minValue, double maxValue, double defaultValue)
        : SimpleSlider(name, minValue, maxValue, defaultValue)
    {
        setSliderStyle();
    }

    void setSliderStyle() override
    {
        slider.setSliderStyle(juce::Slider::LinearVertical);
        slider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50, 20);
        slider.setColour(juce::Slider::trackColourId, juce::Colours::deepskyblue);
        slider.setColour(juce::Slider::thumbColourId, juce::Colours::white);

        label.setJustificationType(juce::Justification::centred);
        label.setFont(juce::Font(14.0f, juce::Font::bold));
        label.setColour(juce::Label::textColourId, juce::Colours::white);
    }
};