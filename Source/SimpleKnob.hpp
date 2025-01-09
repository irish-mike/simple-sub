#pragma once

#include <JuceHeader.h>

/**
 * A simple knob component that places a label at the top,
 * and a rotary slider (with a text box below) below the label.
 */
class SimpleKnob : public juce::Component
{
public:
    /**
     * Creates a SimpleKnob with the given label text, minimum and maximum slider range.
     * The slider is always initialized to 0.
     *
     * @param name      The label text displayed above the knob.
     * @param minValue  The slider's minimum value.
     * @param maxValue  The slider's maximum value.
     */
    SimpleKnob(const juce::String& name, double minValue, double maxValue);

    ~SimpleKnob() override = default;

    /** You can override paint if you want to custom-draw a background, etc. */
    void paint(juce::Graphics& /*g*/) override {}

    /**
     * Resized is called whenever the component’s size changes.
     * We’ll handle the layout of our label and slider here.
     */
    void resized() override;

private:
    juce::Label  knobLabel;
    juce::Slider knobSlider;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SimpleKnob)
};
