#include "SimpleKnob.hpp"
#include "Constants.h" 

SimpleKnob::SimpleKnob(const juce::String& name, double minValue, double maxValue, double defaultValue)
{
    this->setRotarySlider(minValue, maxValue, defaultValue);
    this->setLabel(name);
}

void SimpleKnob::setRotarySlider(double minValue, double maxValue, double defaultValue)
{
    knobSlider.setRange(minValue, maxValue);
    knobSlider.setValue(defaultValue);
    knobSlider.setNumDecimalPlacesToDisplay(2);

    knobSlider.setSliderStyle(juce::Slider::Rotary);
    knobSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50, 20);

    knobSlider.setColour(juce::Slider::rotarySliderFillColourId, juce::Colours::darkgreen);  
    knobSlider.setColour(juce::Slider::rotarySliderOutlineColourId, juce::Colours::darkgrey);  
    knobSlider.setColour(juce::Slider::thumbColourId, juce::Colours::whitesmoke);

    addAndMakeVisible(knobSlider);
}

void SimpleKnob::setLabel(const juce::String& name) 
{
    knobLabel.setText(name, juce::dontSendNotification);
    knobLabel.setJustificationType(juce::Justification::centred);
    knobSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50, 20);

    addAndMakeVisible(knobLabel);
}

void SimpleKnob::resized()
{
    // Our overall bounding box
    auto bounds = getLocalBounds();

    // 1) Top padding
    bounds.removeFromTop(Constants::knobPadding);

    // 2) The label area at the top
    auto labelArea = bounds.removeFromTop(Constants::labelHeight);
    knobLabel.setBounds(labelArea.withSizeKeepingCentre(labelArea.getWidth(), Constants::labelHeight));

    // 3) A bit of space between label and slider
    bounds.removeFromTop(Constants::knobPadding);

    // 4) The slider area (square) below
    auto sliderArea = bounds.removeFromTop(Constants::rotarySliderSize);
    knobSlider.setBounds(sliderArea.withSizeKeepingCentre(Constants::rotarySliderSize, Constants::rotarySliderSize));
}