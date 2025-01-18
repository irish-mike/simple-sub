#pragma once

#include <JuceHeader.h>


class SimpleSynthesiserVoice : public juce::SynthesiserVoice {
public:
    bool canPlaySound(juce::SynthesiserSound*) override;
    void startNote(int midiNoteNumber, float velocity, juce::SynthesiserSound* sound, int currentPitchWheelPosition) override;
    void stopNote(float velocity, bool allowTailOff) override;
    void pitchWheelMoved(int newPitchWheelValue) override;
    void controllerMoved(int controllerNumber, int newControllerValue) override;
    // void aftertouchChanged(int newAftertouchValue) override;
    // void channelPressureChanged(int newChannelPressureValue) override;
    void prepareToPlay(double sampleRate, int samplesPerBlock, int outputChannels);

    void renderNextBlock(juce::AudioBuffer< float > &outputBuffer, int startSample, int numSamples) override;
    // void setCurrentPlaybackSampleRate(double newRate) override;
    // bool isPlayingChannel(int midiChannel) const override;

    

private:
    juce::dsp::Oscillator<float> osc{
        // Lambda that returns a sine wave value for a given phase
        [](float x) { return std::sin(x); }
    };

    juce::dsp::Gain<float> gain;

    juce::ADSR adsr;
    juce::ADSR::ADSR::Parameters adsrParams;
};