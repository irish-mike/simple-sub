#include "SimpleKnob.hpp"
#include "Constants.h" 

SimpleKnob::SimpleKnob(const juce::String& name, double minValue, double maxValue)
{

    // Set the size
    const int totalWidth = Constants::rotarySliderSize + 2 * Constants::knobPadding;

    const int totalHeight = Constants::knobPadding
        + Constants::labelHeight
        + Constants::knobPadding
        + Constants::rotarySliderSize
        + Constants::knobPadding;

    // 10 + 20 + 10 + 125 + 10

    setSize(totalWidth, totalHeight);

    // Configure the label
    knobLabel.setText(name, juce::dontSendNotification);
    knobLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(knobLabel);

    // Configure the slider
    knobSlider.setRange(minValue, maxValue);
    knobSlider.setValue(0.0); // Always start at 0
    knobSlider.setSliderStyle(juce::Slider::Rotary);
    
    // Text box below the rotary knob
    knobSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50, 20);
    addAndMakeVisible(knobSlider);
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
