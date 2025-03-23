## effect baseclass

    -samplerate
    -float inputSample
    -floatDryOutputSample
    -float wetOutputSample
    -bool bypass
# methods
    void prepare(float samplerate)
    float processFrame()
    setDryWet(float dryWet)
    setBypass(bool bypass)

applyEffect(float& input, float& output);

## delaysessie 2:


    check out: final en override keywords.

## WAVESHAPER:

map range [-1, 1] to [0, buffersize-1] 
audio waarde gebruiken om buffer uit te lezen

    simple waveshaper
        aplyeffect
        float[] buffer
