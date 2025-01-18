#pragma once

#include <JuceHeader.h>
#include <juce_dsp/juce_dsp.h>


class SimpleSubAudioProcessor  : public juce::AudioProcessor
{
public:
    SimpleSubAudioProcessor();
    ~SimpleSubAudioProcessor() override;

    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    // Gain parameter: -60 dB (silent) to 0 dB (max)
    void setGain(double newGain)
    {
        DBG("Gain Set: " << newGain);
        gain = newGain;
    }

    // Low-pass filter frequency: 20 Hz to 20,000 Hz
    void setFilterFrequency(double newFrequency)
    {
        DBG("Filter Frequency Set: " << newFrequency);
        lpFilterFrequency = newFrequency;
    }

    // Distortion amount: 0% to 100%
    void setDistortionAmount(double newAmount)
    {
        DBG("Distortion Amount Set: " << newAmount);
        distortionAmount = newAmount;
    }

    // Morph amount: 0% to 100%
    void setMorphAmount(double newAmount)
    {
        DBG("Morph Amount Set: " << newAmount);
        morphAmount = newAmount;
    }

    // Attack time: 0.001 s (1 ms) to 10 s
    void setAttackTime(double newTime)
    {
        DBG("Attack Time Set: " << newTime);
        attackTime = newTime;

        //adsrParams.attack = static_cast<float>(attackTime);
        //adsr.setParameters(adsrParams);
    }

    // Release time: 0.001 s (1 ms) to 10 s
    void setReleaseTime(double newTime)
    {
        DBG("Release Time Set: " << newTime);
        releaseTime = newTime;

        //adsrParams.release = static_cast<float>(releaseTime);
        //adsr.setParameters(adsrParams);
    }

private:
    double gain{ -60.0 };                     // Default: -60 dB
    double lpFilterFrequency{ 20000.0 };      // Default: 20 kHz (fully open)
    double distortionAmount{ 0.0 };           // Default: 0% (no distortion)
    double morphAmount{ 0.0 };                // Default: 0% (no morph)
    double attackTime{ 0.1 };                 // Default: 0.1 s (100 ms)
    double releaseTime{ 0.5 };                // Default: 0.5 s (500 ms)


    double oscillatorFrequency = 440.0;   // default freq; updated by MIDI

    juce::Synthesiser synth;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SimpleSubAudioProcessor)
};
