#pragma once

#include <JuceHeader.h>
#include <vector> // Include for std::vector

// A simple grid layout component that positions components passed to it.
class SimpleGrid : public juce::Component
{
public:
    SimpleGrid(const std::vector<juce::Component*>& components, int rows, int columns, int padding);

    void resized() override;

private:
    std::vector<juce::Component*> components; // Store components in a vector
    int rows, columns, padding;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SimpleGrid)
};