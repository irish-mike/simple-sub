#include "PluginEditor.h"
#include "Constants.h"

#include <juce_gui_basics/juce_gui_basics.h>
using namespace juce;

SimpleSubAudioProcessorEditor::SimpleSubAudioProcessorEditor(SimpleSubAudioProcessor& p)
    : AudioProcessorEditor(&p), audioProcessor(p)
{
    setResizable(true, true);
    addAndMakeVisible(controlPanel);
    Component::setSize(Constants::pluginWidth, Constants::pluginHeight);
}


void SimpleSubAudioProcessorEditor::paint(juce::Graphics& g)
{
    g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId)); // Background
}

void SimpleSubAudioProcessorEditor::resized(){
    // Get the bounds of the plugin editor
    auto bounds = getLocalBounds();

    // Apply padding for the ControlPanel
    controlPanel.setBounds(bounds.reduced(Constants::componentPadding));

    // Maintain the aspect ratio
    this->resizeWithAspect();
}

// Resizes the plugin and maintains aspect ratio set in constants
void SimpleSubAudioProcessorEditor::resizeWithAspect()
{
    // Get the current bounds of the component as a Rectangle object
    Rectangle area = getLocalBounds();

    // Retrieve the current width of the component from its bounds
    const int width = area.getWidth();

    // Explicitly cast the floating-point result to an integer for clarity and safety
    const int height = static_cast<int>(width * Constants::aspectRatio);

    // Call base class setSize with the calculated dimensions
    Component::setSize(width, height);
}

