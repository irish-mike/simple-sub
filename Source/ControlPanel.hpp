#pragma once
#include <JuceHeader.h>

class ControlPanel : public juce::Component
{
public:
    ControlPanel();
    ~ControlPanel() override = default;

    void paint(juce::Graphics& g) override;
    void resized() override;

    void setComponentGrid();

private:

    juce::Slider gainSlider;
    juce::Slider lpFilterSlider;

    juce::Slider distortSlider;
    juce::Slider morphSlider;
    
    juce::Slider attackSlider;
    juce::Slider releaseSlider;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ControlPanel)
};

