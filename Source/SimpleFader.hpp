#pragma once

#include <JuceHeader.h>

class SimpleFader : public juce::Component
{
public:
    /**
     * Creates a SimpleFader with the given label text, minimum and maximum slider range.
     * The slider is always initialized to 0.
     *
     * @param name      The label text displayed below the fader.
     * @param minValue  The slider's minimum value.
     * @param maxValue  The slider's maximum value.
     */
    SimpleFader(const juce::String& name, double minValue, double maxValue, double defaultValue);

    ~SimpleFader() override = default;

    void setFader(double minValue, double maxValue, double defaultValue);

    void setLabel(const juce::String& name);

    /**
     * Resized is called whenever the component’s size changes.
     * We’ll handle the layout of our label and slider here.
     */
    void resized() override;

private:
    juce::Slider faderSlider;
    juce::Label faderLabel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SimpleFader)
};