import simpleaudio as sa
import time
import threading
import random

kick = sa.WaveObject.from_wave_file("python_basics/eventseq/samp/kick.wav")
snare = sa.WaveObject.from_wave_file("python_basics/eventseq/samp/snare.wav")
ride = sa.WaveObject.from_wave_file("python_basics/eventseq/samp/ride.wav")
#test sounds
# kick = sa.WaveObject.from_wave_file("/Users/dylan/Desktop/file wavs:mp3/noise import/samples/piano beneden (9dec)/note 13.wav")
# snare = sa.WaveObject.from_wave_file('/Users/dylan/Desktop/file wavs:mp3/noise import/samples/piano beneden (9dec)/note 68.wav')
# ride = sa.WaveObject.from_wave_file('/Users/dylan/Desktop/file wavs:mp3/noise import/samples/piano beneden (9dec)/note 37.wav')

instruments = [kick, snare, ride]

correctInput = False
# default bpm
bpm = 120
while (not correctInput):
    user_bpm = input("enter a bpm: ")

    # check if we 'received' an empty string
    if not user_bpm:
        # empty string --> use default
        print("Succeeded, bpm is: ", bpm)
        correctInput = True
    elif(user_bpm =="whatthedog"):
        print("whatdog?")
        bpm = 30
        correctInput = True
    else:
        try:
            bpm = float(user_bpm)
            correctInput = True
            print("Succeeded, bpm is: ", bpm)
        except:
            print("Incorrect input - please enter a bpm (or enter nothing - default bpm): ")
quarterNoteDur = 60/bpm



loops = 4
correctInput = False
while (not correctInput):
    user_loops = input("how many loops: ")

    # check if we 'received' an empty string
    if not user_loops:
        # empty string --> use default
        correctInput = True
    elif(user_loops == "whatthedog"): 
        kick = sa.WaveObject.from_wave_file("python_basics/eventseq/samp/woof.wav")
        snare = sa.WaveObject.from_wave_file("python_basics/eventseq/samp/miawu.wav")
        ride = sa.WaveObject.from_wave_file("python_basics/eventseq/samp/0miawu.wav")
        instruments = [kick, snare, ride]
        print("what dog?")
        loops = 10000000
        time.sleep(2)
        print(loops)
        time.sleep(1)
        correctInput = True
    else:
        try:
            loops = float(user_loops)
            correctInput = True
        except:
            print("Incorrect input - please amountofloops (or enter nothing - default): ")
quarterNoteDur = 60/bpm
currentLoop = 0
stepDuration  = quarterNoteDur / 4
totNumEvents = []

# user input 
# numKick = int(input('how many kicks? '))
# numSnare = int(input('how many snares? '))
# numRide = int(input('how many ride? '))

kickEvents = []
snareEvents = []
rideEvents = []

kickDurations = [2,1,2,1,0.5,1]
snareDurations = [1,1,0.5,0.25,1,1,1]
rideDurations = [0.5,1,1,1,0.5,1,1]
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
    for i in range(len(kickDurations)):
        kickEvents.append({
            'timestamp': durations[0][i],
            'instrumentName': "kick",
            'instrument': instruments[0],
            'velocity': 82 * 10
        })
    for i in range(len(snareDurations)):
        snareEvents.append({
            'timestamp': durations[1][i],
            'instrumentName': "snare",
            'instrument': instruments[1],
            'velocity': 82 * 10
        })
    for i in range(len(rideDurations)):
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
def handleEvents(currentLoop, loops):
    totNumEvents.sort(key=getTimeStamp)
    print("dog")
    
    startTime = time.time()
    currentTime = time.time()
    current_timestamp = 0
    increment = 1
    timeToWait = 0

    while True:

            #kijken naar de volgende timestamp en wachten met miliseconden totdat die timestamp of voorbij is of huidig is
            #kijk naar de single_sample_sequencer...
            
            
            #okay so the issue right now is that using Len(durations) gives a length of 3 instaid of 24
            #because the list is filled with 3 lists.
            event = totNumEvents[increment]
            currentTime = time.time()
            if((currentTime - startTime) >= event['timestamp']):
                print("whatthedog: ", currentLoop)
                print("thisdog: ", increment)
                print(len(totNumEvents))
                # print(event['timestamp'])
                playSample(event)
                increment += 1
                if(increment>=len(totNumEvents)-1):
                    startTime = time.time()
                    increment = 0
                    currentLoop+=1
                    if(currentLoop >= loops):
                        break
            else:
                time.sleep(0.001)

handleEvents(currentLoop, loops)

