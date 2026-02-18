# [4 dimensional music effect]

### CUSTOM FOCUS
![image](http://cagedotlog.com/backend/elecflute/design/elecFluteII.png)

i want to be able to use this effect in a live setting on my flute, so i dont need a plugin. although i will put it in the plugin. 
for this project i want to make a single slider which i can glue onto the flute.

the project will consist of 3 effects, and it goes like this: 
[Simple timestretcher -> ladder filter -> reverb]
using these effects and 1 slider i can effectively "throw" the incoming signal into the fourth dimension. you can imagine it by imagining what it would sound like to slow down time while also shrinking yourself at the same moment. 

## de slider bestuurt deze dingen:
    * de stretch speed van                  (0 - 100)
    * de pitch shifting                     (samen met de stretch speed)
    * de ladder filter low pass             (0Hz - 20000Hz)
    * de reverb feedback                    (0.0 - 2.0)

## MOSCOW

    Must:
    - timestretching (with interpolation)
    - reverb
    Should:
    - ladder filter
    - seperate pitch controll
    Could: 
    - Stereo
    Wont:
    - use the buttons on the trumpet because there are already buttons on the trumpet


![image](http://cagedotlog.com/backend/elecflute/design/prototype.png)

## Leerdoelen

De CSD’er kan het beoogde ontwerp afstellen op de eigen capaciteit, zowel wbt het afbakenen ter voorkoming van overbelasting als opschalen ter voorkoming van onderbelasting.

![image](http://cagedotlog.com/backend/elecflute/design/parts%20of%20elecflute.png)

[onderzoekpunten]
- wat is de mmax aantal samples die je kan skippen voor je een click krijgt

