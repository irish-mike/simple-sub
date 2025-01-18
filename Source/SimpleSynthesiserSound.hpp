#pragma once

#include <JuceHeader.h>

class SimpleSynthesiserSound : public juce::SynthesiserSound
{
public:
	bool appliesToNote(int midiNoteNumber) override { return true; }
	bool appliesToChannel(int midiChannel) override { return true; }
};