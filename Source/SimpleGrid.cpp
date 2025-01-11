#include "SimpleGrid.hpp"

SimpleGrid::SimpleGrid(const std::vector<juce::Component*>& components, int rows, int columns, int padding)
    : components(components), rows(rows), columns(columns), padding(padding)
{
    // Add each component to the grid and make it visible
    for (auto* component : components)
    {
        addAndMakeVisible(component);
    }
}

void SimpleGrid::resized()
{
    // Calculate the size of each cell
    int cellWidth = (getWidth() - padding * (columns + 1)) / columns;
    int cellHeight = (getHeight() - padding * (rows + 1)) / rows;

    // Position each component in the grid
    for (int i = 0; i < components.size(); ++i)
    {
        int row = i / columns; // Row index
        int col = i % columns; // Column index

        // Calculate bounds for each component
        int x = padding + col * (cellWidth + padding);
        int y = padding + row * (cellHeight + padding);

        if (auto* component = components[i])
        {
            component->setBounds(x, y, cellWidth, cellHeight);
        }
    }
}