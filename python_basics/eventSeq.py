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

kickDurations = [1, 0.5 ,0.75 ,0.5 ,0.25 ,1]
snareDurations = [1, 0.5 ,0.5 ,1 ,0.25 ,0.5]
rideDurations = [1,1,1,1,0.5,1,1,1]
durations = [kickDurations, snareDurations, rideDurations]
numInstruments = 3


timestamp = 0
instrumentName = ""
instrument = sa.WaveObject
velocity = int
duration = int 
stamps = []


def durationsToTimestamps16th(durations):
    for i in range(numInstruments):
        cumulative_timestamp = 0
        stamps.clear()  # Clear the stamps list for each instrument
        for currentstamp in range(len(durations[i])):
            cumulative_timestamp += float(durations[i][currentstamp] * quarterNoteDur)
            stamps.append(cumulative_timestamp)
        durations[i] = stamps.copy()
    return durations

durationsToTimestamps16th(durations)

def eventGen(durations):
    for i in range(numKick):
        kickEvents.append({
            'timestamp': durations[0][i],
            'instrumentName': "kick",
            'instrument': instruments[0],
            'velocity': 82 * 10
        })
    for i in range(numSnare):
        snareEvents.append({
            'timestamp': durations[1][i],
            'instrumentName': "snare",
            'instrument': instruments[1],
            'velocity': 82 * 10
        })
    for i in range(numRide):
        rideEvents.append({
            'timestamp': durations[2][i],
            'instrumentName': "ride",
            'instrument': instruments[2],
            'velocity': 82 * 10
        })
eventGen(durations)
totNumEvents = kickEvents + snareEvents + rideEvents
print(totNumEvents)

def getTimeStamp(totNumEvents):
    return totNumEvents['timestamp']

            
def handleEvents(stepDuration, loops):
    totNumEvents.sort(key=getTimeStamp)

    for loop in range(loops):
        startTime = time.time()
        print(loop )
        print("-loop")
        current_timestamp = 0
        for event in totNumEvents:
            current_timestamp += stepDuration
            timeToWait = current_timestamp - (time.time() - startTime)
            if timeToWait > 0:
                time.sleep(timeToWait)
            event['instrument'].play()

handleEvents(stepDuration, loops)

