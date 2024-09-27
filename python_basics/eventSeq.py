import simpleaudio as sa
import time
import random

kick = sa.WaveObject.from_wave_file("/Users/dylan/Desktop/file wavs:mp3/noise import/samples/drum samples/cropped/kick.wav")
snare = sa.WaveObject.from_wave_file("/Users/dylan/Desktop/file wavs:mp3/noise import/samples/drum samples/cropped/snare.wav")
ride = sa.WaveObject.from_wave_file("/Users/dylan/Desktop/file wavs:mp3/noise import/samples/drum samples/cropped/ride.wav")

instruments = [kick, snare, ride]

numOfEvents = int(input("how many total events? "))
numKick = 4
numSnare = 6
numRide = 8
# numKick = int(input('how many kicks? '))
# numSnare = int(input('how many snares? '))
# numRide = int(input('how many ride? '))

kickEvents = []
timestamp = 0
instrumentName = ""
instrument = sa.WaveObject
velocity = int
duration = int 

def eventGen():
    for i in range(numOfEvents):
        kickEvents.append(int)
        
        kickEvents[i] = {
            'timestamp': 10 + i,
            'instrumentName': "kick",
            'instrument': instruments[1],
            'velocity': 82 * 10, 
            'duration': 500 * 10  
        }
eventGen()

def handleEvents():
    for events in range(len(kickEvents)):
        print(kickEvents[events]['timestamp'])    
        print(kickEvents[events]['instrumentName'])    
        print(kickEvents[events]['instrument'])    
        print(kickEvents[events]['velocity'])    
        print(kickEvents[events]['duration'])    
        time.sleep(randint(0,1))
        kickEvents[events]['instrument'].play()
handleEvents()
