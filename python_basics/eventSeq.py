import simpleaudio as sa
import time
import random

kick = sa.WaveObject.from_wave_file("/Users/dylan/Cage/localsample/kick.wav")
snare = sa.WaveObject.from_wave_file("/Users/dylan/Cage/localsample/snare.wav")
ride = sa.WaveObject.from_wave_file("/Users/dylan/Cage/localsample/ride.wav")

instruments = [kick, snare, ride]

numOfEvents = int(input("how many total events? "))
quarterNoteDur = 60/int(input("what bpm? "))
loops = int(input("how many loops?: "))
stepDuration  = quarterNoteDur 
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



# qnSequence = [1.5, 1, 1, 0.5]

def eventGen():
    for i in range(numKick):
        kickEvents.append(int)
        
        kickEvents[i] = {
            'timestamp':  1 + i,
            'instrumentName': "kick",
            'instrument': instruments[0],
            'velocity': 82 * 10, 
            # 'duration': 500 * 10  
        }
    for i in range(numSnare):
        snareEvents.append(int)
        
        snareEvents[i] = {
            'timestamp':  1+ (i*2),
            'instrumentName': "snare",
            'instrument': instruments[1],
            'velocity': 82 * 10, 
            # 'duration': 500 * 10  
        }
    for i in range(numRide):
        rideEvents.append(int)
        
        rideEvents[i] = {
            'timestamp':  1+ (i * random.randint(0,2)),
            'instrumentName': "ride",
            'instrument': instruments[2],
            'velocity': 82 * 10, 
            # 'duration': 500 * 10  
        }
eventGen()
totNumEvents = kickEvents + snareEvents + rideEvents

def getTimeStamp(totNumEvents):
    return totNumEvents['timestamp']

def handleEvents(stepDuration, loops):
    startTime = time.time()

    totNumEvents.sort(key=getTimeStamp)

    for loop in range(loops):
        for events in range(len(totNumEvents)): 
            currentTime = time.time()
            nxtTimeStamp = stepDuration * (totNumEvents[events]['timestamp'] * loop)
            
            print("1 calc: ",currentTime - startTime)
            print(nxtTimeStamp)

            timeToWait = nxtTimeStamp - (currentTime - startTime)
        
            if timeToWait > 0:
                time.sleep(timeToWait)
            totNumEvents[events]['instrument'].play()

handleEvents(stepDuration, loops)

