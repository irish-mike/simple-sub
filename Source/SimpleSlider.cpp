#include "SimpleSlider.hpp"
#include "Constants.h"

SimpleSlider::SimpleSlider(const juce::String& name, double minValue, double maxValue, double defaultValue)
{
    slider.setRange(minValue, maxValue);
    slider.setValue(defaultValue);
    slider.addListener(this);
    slider.setNumDecimalPlacesToDisplay(2);

    label.setText(name, juce::dontSendNotification);

    addAndMakeVisible(slider);
    addAndMakeVisible(label);
}

SimpleSlider::~SimpleSlider()
{
    slider.removeListener(this);
}


void SimpleSlider::resized()
{
    // Layout the components
    auto bounds = getLocalBounds();

    // Reserve space for the fader
    auto faderArea = bounds.removeFromTop(bounds.getHeight() - Constants::labelHeight);
    slider.setBounds(faderArea.reduced(Constants::componentPadding));

    // Label goes below the fader
    auto labelArea = bounds;
    label.setBounds(labelArea.withSizeKeepingCentre(labelArea.getWidth(), Constants::labelHeight));
}

void SimpleSlider::sliderValueChanged(juce::Slider* s)
{
    if (s == &slider && onValueChanged)
        onValueChanged(s->getValue());
}