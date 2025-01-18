#include "ControlPanel.hpp"
#include "Constants.h"
using namespace juce;

using ProcessorSetter = void (SimpleSubAudioProcessor::*)(double);

ControlPanel::ControlPanel(SimpleSubAudioProcessor& processor) : processor(processor)
{
    this->registerListeners();
    addAndMakeVisible(gainSlider);
    addAndMakeVisible(lpFilterSlider);
    addAndMakeVisible(distortSlider);
    addAndMakeVisible(morphSlider);
    addAndMakeVisible(attackSlider);
    addAndMakeVisible(releaseSlider);
}

void ControlPanel::registerListeners()
{
    auto connectSlider = [this](SimpleSlider& slider, ProcessorSetter setter)
        {
            slider.onValueChanged = [processor = &this->processor, setter](double newValue)
                {
                    (processor->*setter)(newValue);
                };
        };

    connectSlider(gainSlider, &SimpleSubAudioProcessor::setGain);
    connectSlider(lpFilterSlider, &SimpleSubAudioProcessor::setFilterFrequency);
    connectSlider(distortSlider, &SimpleSubAudioProcessor::setDistortionAmount);
    connectSlider(morphSlider, &SimpleSubAudioProcessor::setMorphAmount);
    connectSlider(attackSlider, &SimpleSubAudioProcessor::setAttackTime);
    connectSlider(releaseSlider, &SimpleSubAudioProcessor::setReleaseTime);
}
void ControlPanel::paint(juce::Graphics& g)
{
    // Create a gradient for the background
    juce::ColourGradient backgroundGradient(
        juce::Colours::darkgrey, 0, 0,                    // Start color and position
        juce::Colours::black, getWidth(), getHeight(),    // End color and position
        false                                             // Not radial
    );

    // Set the gradient as the fill
    g.setGradientFill(backgroundGradient);

    // Fill a rounded rectangle with the gradient
    auto bounds = getLocalBounds().toFloat(); // Get bounds as a float rectangle
    float cornerRadius = 10.0f;               // Radius for rounded corners
    g.fillRoundedRectangle(bounds, cornerRadius);

    // Draw an outline around the rounded rectangle
    g.setColour(juce::Colours::white);        // Outline color
    g.drawRoundedRectangle(bounds, cornerRadius, 2.0f); // Outline thickness: 2.0f
}

void ControlPanel::resized()
{
    this->setComponentGrid();
}

void ControlPanel::setComponentGrid() {
    Grid grid;

    grid.rowGap = juce::Grid::Px(Constants::componentPadding);
    grid.columnGap = juce::Grid::Px(Constants::componentPadding);

    using Track = Grid::TrackInfo;

    grid.templateColumns = { Track(1_fr), Track(1_fr), Track(1_fr), Track(1_fr) };
    grid.templateRows = { Track(1_fr), Track(1_fr) };

    grid.autoFlow = Grid::AutoFlow::column;

    grid.items.addArray({ 
        GridItem(distortSlider),
        GridItem(morphSlider),
        GridItem(attackSlider),
        GridItem(releaseSlider),
        GridItem(lpFilterSlider).withArea(GridItem::Span(2), {}),
        GridItem(gainSlider).withArea(GridItem::Span(2), {})});

    grid.performLayout(getLocalBounds().reduced(Constants::componentPadding));
}