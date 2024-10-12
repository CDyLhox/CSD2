import simpleaudio as sa
import time
import threading
import random

kick = sa.WaveObject.from_wave_file("/Users/dylan/Cage/localsample/kick.wav")
snare = sa.WaveObject.from_wave_file("/Users/dylan/Cage/localsample/snare.wav")
ride = sa.WaveObject.from_wave_file("/Users/dylan/Cage/localsample/ride.wav")
#test sounds
kick = sa.WaveObject.from_wave_file("/Users/dylan/Desktop/file wavs:mp3/noise import/samples/piano beneden (9dec)/note 13.wav")
snare = sa.WaveObject.from_wave_file('/Users/dylan/Desktop/file wavs:mp3/noise import/samples/piano beneden (9dec)/note 68.wav')
ride = sa.WaveObject.from_wave_file('/Users/dylan/Desktop/file wavs:mp3/noise import/samples/piano beneden (9dec)/note 37.wav')

instruments = [kick, snare, ride]

numOfEvents = int(input("how many total events? "))
quarterNoteDur = 60/int(input("what bpm? "))
loops = int(input("how many loops?: "))
stepDuration  = quarterNoteDur / 4
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

kickDurations = [1,1,1,1,0.5,1,1,1]
snareDurations = [1,1,1,1,0.5,1,1,1]
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
    print(durations)
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


def getTimeStamp(totNumEvents):
    return totNumEvents['timestamp']

def playSample(event):
    event['instrument'].play()
    print(event['instrumentName'])

            
def handleEvents(stepDuration, loops):
    totNumEvents.sort(key=getTimeStamp)
    print(totNumEvents)
    time.sleep(9)
    print("starting")
    time.sleep(1)
    
    startTime = time.time()
    currentTime = time.time()
    current_timestamp = 0
    increment = 0
    timeToWait = 0
    while increment/numOfEvents*2 < loops:
        # for loop in range(loops):
            # print(loop )
            # print("-loop")
            #kijken naar de volgende timestamp en wachten met miliseconden totdat die timestamp of voorbij is of huidig is
            #kijk naar de single_sample_sequencer...
        # for event in totNumEvents:
            event = totNumEvents[increment]
            
            currentTime = time.time()
            # print(timeToWait)
            

            if((currentTime - startTime) >= event['timestamp']):
                # print("timetowait: ",timeToWait)
                # print("current_timestamp: ",current_timestamp)
                # print(timeToWait, " time to wait")
                print("whatthedog: ")
                playSample(event)
                # print(event['instrumentName'])
                # print(event['timestamp'], "timestamp of event")
                increment+=1
                # if(event['timestamp'] >= current_timestamp):
                #     print("new timestamp")
                #     current_timestamp += stepDuration
                #     timeToWait = current_timestamp + (currentTime - startTime)
                # else:
                #     time.sleep(0.01)

            else:
                time.sleep(0.001)

handleEvents(stepDuration, loops)

