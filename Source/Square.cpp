#include "Square.hpp"

// Constructor
Square::Square(int x, int y, int size, juce::Colour colour)
    : squareColour(colour) // Initialize the color
{
    setBounds(x, y, size, size); // Set position and size
}

// Destructor
Square::~Square() {}

// Paint method
void Square::paint(juce::Graphics& g)
{
    // Fill the square with the specified color
    g.fillAll(squareColour);

    // Optional: Draw a border around the square
    g.setColour(juce::Colours::black);
    g.drawRect(0, 0, getWidth(), getHeight(), 2); // 2-pixel thick border
}
