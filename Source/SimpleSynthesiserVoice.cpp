#include "SimpleSynthesiserVoice.hpp"
#include "SimpleSynthesiserSound.hpp"

bool SimpleSynthesiserVoice::canPlaySound(juce::SynthesiserSound* sound)
{
	return dynamic_cast<const SimpleSynthesiserSound*> (sound) != nullptr;
}

void SimpleSynthesiserVoice::startNote(int midiNoteNumber, float velocity, juce::SynthesiserSound* sound, int currentPitchWheelPosition)
{
    DBG("Start Note: " << midiNoteNumber); // Debug output
    osc.setFrequency(juce::MidiMessage::getMidiNoteInHertz(midiNoteNumber));
    adsr.noteOn();
}

void SimpleSynthesiserVoice::stopNote(float velocity, bool allowTailOff)
{
    adsr.noteOff();

    if (!allowTailOff || !adsr.isActive())
        clearCurrentNote();

}

void SimpleSynthesiserVoice::pitchWheelMoved(int newPitchWheelValue) {}

void SimpleSynthesiserVoice::controllerMoved(int controllerNumber, int newControllerValue)
{
}

void SimpleSynthesiserVoice::prepareToPlay(double sampleRate, int samplesPerBlock, int outputChannels)
{
    juce::dsp::ProcessSpec spec;
    spec.sampleRate = sampleRate;
    spec.maximumBlockSize = samplesPerBlock;
    spec.numChannels = outputChannels;

    // Prepare oscillator
    osc.prepare(spec);
    osc.setFrequency(440.0f);

    // Prepare final gain
    gain.prepare(spec);
    gain.setGainLinear(1.0f);

    // ADSR parameters (in seconds)
    adsrParams.attack = 0.01f;
    adsrParams.decay = 0.0f;
    adsrParams.sustain = 1.0f;
    adsrParams.release = 0.01f;

    adsr.setSampleRate(sampleRate);
    adsr.setParameters(adsrParams);

    // Make sure ADSR is in a "note off" state initially
    adsr.noteOff();
}

void SimpleSynthesiserVoice::renderNextBlock(juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples)
{
    juce::dsp::AudioBlock<float> audioBlock(outputBuffer);
    juce::dsp::ProcessContextReplacing<float> context(audioBlock);

    // Generate audio using the oscillator
    osc.process(context);

    // Convert decibel 'gain' to linear and apply it
    float linearGain = juce::Decibels::decibelsToGain((float)-6);
    gain.setGainLinear(linearGain); // e.g., based on parameter
    gain.process(context); // Apply final amplitude

    // Apply ADSR envelope to the buffer
    adsr.applyEnvelopeToBuffer(outputBuffer, startSample, numSamples);
}

