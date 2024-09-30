import simpleaudio as sa
import time
import random

kick = sa.WaveObject.from_wave_file("/Users/dylan/Desktop/file wavs:mp3/noise import/samples/drum samples/cropped/kick.wav")
snare = sa.WaveObject.from_wave_file("/Users/dylan/Desktop/file wavs:mp3/noise import/samples/drum samples/cropped/snare.wav")
ride = sa.WaveObject.from_wave_file("/Users/dylan/Desktop/file wavs:mp3/noise import/samples/drum samples/cropped/ride.wav")

instruments = [kick, snare, ride]

numOfEvents = int(input("how many total events? "))
totNumEvents = []
numKick = 4
numSnare = 6
numRide = 8
# user input 
# numKick = int(input('how many kicks? '))
# numSnare = int(input('how many snares? '))
# numRide = int(input('how many ride? '))

kickEvents = []
snareEvents = []
rideEvents = []
timestamp = 0
instrumentName = ""
instrument = sa.WaveObject
velocity = int
duration = int 

def eventGen():
    for i in range(numKick):
        kickEvents.append(int)
        
        kickEvents[i] = {
            'timestamp': 10 + i,
            'instrumentName': "kick",
            'instrument': instruments[0],
            'velocity': 82 * 10, 
            # 'duration': 500 * 10  
        }
    for i in range(numSnare):
        snareEvents.append(int)
        
        snareEvents[i] = {
            'timestamp': 10 + i,
            'instrumentName': "snare",
            'instrument': instruments[1],
            'velocity': 82 * 10, 
            # 'duration': 500 * 10  
        }
    for i in range(numRide):
        rideEvents.append(int)
        
        rideEvents[i] = {
            'timestamp': 10 + i,
            'instrumentName': "ride",
            'instrument': instruments[2],
            'velocity': 82 * 10, 
            # 'duration': 500 * 10  
        }
eventGen()
totNumEvents = kickEvents + snareEvents + rideEvents

def handleEvents():
    print(totNumEvents)
    random.shuffle(totNumEvents)
    for events in range(len(totNumEvents)):
        print(totNumEvents[events]['timestamp'])    
        print(totNumEvents[events]['instrumentName'])    
        print(totNumEvents[events]['instrument'])    
        print(totNumEvents[events]['velocity'])    
        # print(totNumEvents[events]['duration'])    
        time.sleep(random.random())
        totNumEvents[events]['instrument'].play()
handleEvents()
