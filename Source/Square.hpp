#pragma once

#include <juceHeader.h>

class Square : public juce::Component
{
public:
    Square(int x, int y, int size, juce::Colour colour);
    ~Square() override;

    void paint(juce::Graphics&) override;

private:
    juce::Colour squareColour;
};
