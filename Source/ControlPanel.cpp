#include "ControlPanel.hpp"
#include "Constants.h"
using namespace juce;

ControlPanel::ControlPanel()
{
    // Gain Slider
    gainSlider.setSliderStyle(juce::Slider::LinearVertical);
    gainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50, 20);
    gainSlider.setColour(juce::Slider::thumbColourId, juce::Colours::skyblue);
    gainSlider.setColour(juce::Slider::trackColourId, juce::Colours::deepskyblue);
    addAndMakeVisible(gainSlider);

    // LP Filter Slider
    lpFilterSlider.setSliderStyle(juce::Slider::LinearVertical);
    lpFilterSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50, 20);
    lpFilterSlider.setColour(juce::Slider::thumbColourId, juce::Colours::yellowgreen);
    lpFilterSlider.setColour(juce::Slider::trackColourId, juce::Colours::limegreen);
    addAndMakeVisible(lpFilterSlider);

    // Distort Slider
    distortSlider.setSliderStyle(juce::Slider::Rotary);
    distortSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50, 20);
    distortSlider.setColour(juce::Slider::rotarySliderFillColourId, juce::Colours::crimson);
    distortSlider.setColour(juce::Slider::rotarySliderOutlineColourId, juce::Colours::darkred);
    distortSlider.setColour(juce::Slider::thumbColourId, juce::Colours::white);
    addAndMakeVisible(distortSlider);

    // Morph Slider
    morphSlider.setSliderStyle(juce::Slider::Rotary);
    morphSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50, 20);
    morphSlider.setColour(juce::Slider::rotarySliderFillColourId, juce::Colours::orange);
    morphSlider.setColour(juce::Slider::rotarySliderOutlineColourId, juce::Colours::darkorange);
    morphSlider.setColour(juce::Slider::thumbColourId, juce::Colours::black);
    addAndMakeVisible(morphSlider);

    // Attack Slider
    attackSlider.setSliderStyle(juce::Slider::Rotary);
    attackSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50, 20);
    attackSlider.setColour(juce::Slider::rotarySliderFillColourId, juce::Colours::lightblue);
    attackSlider.setColour(juce::Slider::rotarySliderOutlineColourId, juce::Colours::blue);
    attackSlider.setColour(juce::Slider::thumbColourId, juce::Colours::darkblue);
    addAndMakeVisible(attackSlider);

    // Release Slider
    releaseSlider.setSliderStyle(juce::Slider::Rotary);
    releaseSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50, 20);
    releaseSlider.setColour(juce::Slider::rotarySliderFillColourId, juce::Colours::violet);
    releaseSlider.setColour(juce::Slider::rotarySliderOutlineColourId, juce::Colours::purple);
    releaseSlider.setColour(juce::Slider::thumbColourId, juce::Colours::white);
    addAndMakeVisible(releaseSlider);

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

    grid.items.addArray({ GridItem(distortSlider),
                                GridItem(morphSlider),
                                GridItem(attackSlider),
                                GridItem(releaseSlider),
                                GridItem(lpFilterSlider).withArea(GridItem::Span(2), {}),
                                GridItem(gainSlider).withArea(GridItem::Span(2), {}),
        });

    grid.performLayout(getLocalBounds().reduced(Constants::componentPadding));
}