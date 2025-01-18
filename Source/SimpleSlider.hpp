#pragma once

#include <JuceHeader.h>

class SimpleSlider : public juce::Component, private juce::Slider::Listener
{
public:
    // A callback that the parent can set to handle changes
    std::function<void(double)> onValueChanged;

    /**
     * Creates a SimpleSlider with the given label text, minimum and maximum slider range.
     * The slider is always initialized to 0.
     *
     * @param name      The label text displayed below the fader.
     * @param minValue  The slider's minimum value.
     * @param maxValue  The slider's maximum value.
     */
    SimpleSlider(const juce::String& name, double minValue, double maxValue, double defaultValue);

    ~SimpleSlider() override;

    virtual void setSliderStyle() = 0;

    /**
     * Resized is called whenever the component’s size changes.
     * We’ll handle the layout of our label and slider here.
     */
    void resized() override;

    void sliderValueChanged(juce::Slider* s) override;

protected:
    juce::Slider slider;
    juce::Label label;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SimpleSlider)
};