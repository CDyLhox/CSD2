import simpleaudio as sa
import time
import random

kick = [sa.WaveObject.from_wave_file("python_basics/Ffolder/samp/kick01.wav"), 
        sa.WaveObject.from_wave_file("python_basics/Ffolder/samp/roundkick01.wav") ]


snare = [sa.WaveObject.from_wave_file("python_basics/Ffolder/samp/snare.wav"),
         sa.WaveObject.from_wave_file("python_basics/Ffolder/samp/brushsnare01.wav"),
         sa.WaveObject.from_wave_file("python_basics/Ffolder/samp/brushsnare02.wav"),
         sa.WaveObject.from_wave_file("python_basics/Ffolder/samp/brushsnare03.wav"),
         sa.WaveObject.from_wave_file("python_basics/Ffolder/samp/brushsnare04.wav"),]
ride = sa.WaveObject.from_wave_file("python_basics/Ffolder/samp/ride.wav")
#test sounds


instruments = [kick, snare, ride]
# ===== userinput =====
# def userinput():
correctInput = False
# default bpm
bpm = 190
while (not correctInput):
    user_bpm = input("enter a bpm: ")

    # check if we 'received' an empty string
    # gebaseerd op code uit voorbeelden
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
                                                                ##negatieve getallen uitfilteren.
                                                                #zet user input in een getSettings() def. slaat de settings op in een dictionary
while (not correctInput):
    user_loops = input("how many loops: ")

    # check if we 'received' an empty string
    # gebaseerd op code uit voorbeelden
    if not user_loops:
        # empty string --> use default
        correctInput = True
    elif(user_loops == "whatthedog"): 
        kick = sa.WaveObject.from_wave_file("python_basics/Ffolder/samp/woof.wav")
        snare = sa.WaveObject.from_wave_file("python_basics/Ffolder/samp/miawu.wav")
        ride = sa.WaveObject.from_wave_file("python_basics/Ffolder/samp/0miawu.wav")
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
    # return currentLoop, stepDuration
totNumEvents = []



kickEvents = []
snareEvents = []
rideEvents = []

kickDurations = [2,1,2,1,0.5,1]
snareDurations = [1,1,0.5,0.25,1,1,1]
rideDurations = [0.5,1,1,1,0.5,1,1]
durations = [kickDurations, snareDurations, rideDurations]
numInstruments = 3


timestamp = 0

instrument = sa.WaveObject
velocity = int
duration = int 
stamps = []

# ===== Generate euclidean pattern and turn durations to 16th notes with bpm =====
def eucliRyGen(durations): #euclidean rhythm generation
    numPulses = int(input("how many pulses? "))
    for o in range(3):
        instrumentnames = ["kick","snare","ride"]
        numNotes = int(input(f"how many {instrumentnames[o]} notes? "))
        sequence = []
        dur = int
        restValue = int
        
        dur = int(numPulses/numNotes)
        sequence = [dur]*numNotes
        for i in range(numNotes):
            sequence[i] = dur
            #dur*i+(dur*restValue)
        restValue = numPulses - (numNotes * dur)
        for u in range(round(restValue)):
            sequence[u]+= 1
        durations[o] = sequence.copy()
        print(sequence)
    return(durations)
eucliRyGen (durations)

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


#===== Generate events =====

def eventGen(durations):
    #may be duplicate code! 
    velo = 100
    print(durations)
    for i in range(len(durations[0])):
        print(durations[0], "kicks")
        kickEvents.append({
            'timestamp': durations[0][i],
            'instrumentName': "kick",
            'instrument': instruments[0][random.randint(0,1)],
            'velocity': velo
        })
    for i in range(len(durations[1])):
        snareEvents.append({
            'timestamp': durations[1][i],
            'instrumentName': "snare",
            'instrument': instruments[1][random.randint(0,4)],
            'velocity': velo
        })
    for i in range(len(durations[2])):
        rideEvents.append({
            'timestamp': durations[2][i],
            'instrumentName': "ride",
            'instrument': instruments[2],
            'velocity': velo
        })
eventGen(durations)




# ===== playsample, sort eventtimestamps, and handleevents =====
totNumEvents = kickEvents + snareEvents + rideEvents

def playSample(event):
    event['instrument'].play()
    print(event['instrumentName'])
    
def getTimeStamp(totNumEvents):
    return totNumEvents['timestamp']
           
def handleEvents(currentLoop, loops):
    totNumEvents.sort(key=getTimeStamp)
    
    startTime = time.time()
    currentTime = time.time()
    increment = 0
    

    while True:
            
            #kijken naar de volgende timestamp en wachten met miliseconden totdat die timestamp of voorbij is of huidig is
            #kijk naar de single_sample_sequencer...
            event = totNumEvents[increment]
            currentTime = time.time()
            if((currentTime - startTime) >= event['timestamp']):
                print("whatthedog(loop): ", currentLoop+1)
                
                playSample(event)
                increment += 1
                #if the amount of samples played is equal to the totnumevents
                if(increment>=len(totNumEvents)):
                    startTime = time.time()
                    increment = 0
                    currentLoop+=1
                    if(currentLoop >= loops):
                        if (input("would you like to repeat the loops? y/n ") == "y"):
                            startTime = time.time()
                            currentLoop = 0
                        else:
                            break
            else:
                time.sleep(0.01)

handleEvents(currentLoop, loops)

