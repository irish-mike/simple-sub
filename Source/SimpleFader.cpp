#include "SimpleFader.hpp"
#include "Constants.h"

SimpleFader::SimpleFader(const juce::String& name, double minValue, double maxValue, double defaultValue)
{
    this->setFader(minValue, maxValue, defaultValue);
    this->setLabel(name);
}

void SimpleFader::setFader(double minValue, double maxValue, double defaultValue) {
    
    faderSlider.setRange(minValue, maxValue);
    faderSlider.setValue(defaultValue);

    faderSlider.setSliderStyle(juce::Slider::LinearVertical);
    faderSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50, 20);
    
    faderSlider.setColour(juce::Slider::trackColourId, juce::Colours::deepskyblue);
    faderSlider.setColour(juce::Slider::thumbColourId, juce::Colours::white);

    addAndMakeVisible(faderSlider);
}

void SimpleFader::setLabel(const juce::String& name) {

    faderLabel.setText(name, juce::dontSendNotification);
    faderLabel.setJustificationType(juce::Justification::centred);
    faderLabel.setFont(juce::Font(14.0f, juce::Font::bold));
    faderLabel.setColour(juce::Label::textColourId, juce::Colours::white);

    addAndMakeVisible(faderLabel);
}

void SimpleFader::resized()
{
    // Layout the components
    auto bounds = getLocalBounds();

    // Reserve space for the fader
    auto faderArea = bounds.removeFromTop(bounds.getHeight() - Constants::labelHeight);
    faderSlider.setBounds(faderArea.reduced(Constants::componentPadding));

    // Label goes below the fader
    auto labelArea = bounds;
    faderLabel.setBounds(labelArea.withSizeKeepingCentre(labelArea.getWidth(), Constants::labelHeight));
}