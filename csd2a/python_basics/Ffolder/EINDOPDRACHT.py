import simpleaudio as sa
import time
import random
from midiutil import MIDIFile

        #MUST
        ## add user input file naming 
        #find out how to edit file path writing
        #add comments..
        
        #SHOULD BE
        #meer vloeiende ritmes
        #kijken of multipulse vatbaar en nice is. ik dnek nu dat met modulo beste zou werken 
    
        #COULD BE
        #swing toevoegen


prompt = input("would you like to run the program? y/n ")  
while prompt == "y":  
    kick = [sa.WaveObject.from_wave_file("csd2a/python_basics/Ffolder/samp/kick01.wav"), 
            sa.WaveObject.from_wave_file("csd2a/python_basics/Ffolder/samp/roundkick01.wav") ]


    snare = [sa.WaveObject.from_wave_file("csd2a/python_basics/Ffolder/samp/snare.wav"),
            sa.WaveObject.from_wave_file("csd2a/python_basics/Ffolder/samp/brushsnare01.wav"),
            sa.WaveObject.from_wave_file("csd2a/python_basics/Ffolder/samp/brushsnare02.wav"),
            sa.WaveObject.from_wave_file("csd2a/python_basics/Ffolder/samp/brushsnare03.wav"),
            sa.WaveObject.from_wave_file("csd2a/python_basics/Ffolder/samp/brushsnare04.wav"),]
    ride = sa.WaveObject.from_wave_file("csd2a/python_basics/Ffolder/samp/ride.wav")
    instruments = [kick, snare, ride]


    # ===== userinput =====
    #--loopinput--
    correctInput = False
    bpm = 190
    while (not correctInput):
        user_bpm = input("enter a bpm: ")


        # gebaseerd op code uit voorbeelden
        if not user_bpm:
            # empty string --> use default
            print("Succes, bpm is: ", bpm)
            correctInput = True
        elif(user_bpm =="whatthedog"):
            print("whatdog?")
            bpm = 30
            correctInput = True            
        else:
            try:
                bpm = float(user_bpm)
                correctInput = True
                print("Succes, bpm is: ", bpm)
                if(bpm < 100):
                    print("its your funeral buddy ")
            except bpm > 400 or bpm <= 0:
                print("incorrect input - please enter a bpm between 1 and 400")
            
            except ValueError:
                print("Incorrect input - please enter a bpm (or enter nothing - default bpm): ")
    quarterNoteDur = 60/bpm
    stepDuration  = quarterNoteDur / 4
    #--loopinput--
    loops = 4
    correctInput = False
    while (not correctInput):
        user_loops = input("how many loops: ")

        # check if we 'received' an empty string
        # gebaseerd op code uit voorbeelden
        if not user_loops:
            # empty string --> use default
            correctInput = True
            print(f"succes, amount of loops is now: {loops}")
        elif(user_loops == "whatthedog"): 
            kick.append(sa.WaveObject.from_wave_file("csd2a/python_basics/Ffolder/samp/woof.wav"))
            snare.append(sa.WaveObject.from_wave_file("csd2a/python_basics/Ffolder/samp/miawu.wav"))
            ride = sa.WaveObject.from_wave_file("csd2a/python_basics/Ffolder/samp/0miawu.wav")
            instruments = [kick, snare, ride]
            print("what dog?..")
            loops = 10000000
            time.sleep(2)
            print(loops)
            time.sleep(1)
            correctInput = True
        else:
            try:
                loops = float(user_loops)
                print(f"succes, amount of loops is now: {loops}")
                correctInput = True
            except loops < 0:
                print("incorrect input - please enter valid loopamounts (or enter nothing - 4 loops): ")
            except:
                print("Incorrect input - please amountofloops (or enter nothing - default): ")
    currentLoop = 0








 

    # ===== Generate euclidean pattern and turn durations to 16th notes with bpm =====
    
    
   
    totNumEvents = []
    durations = [[],[],[]]
    def eucliRyGen(durations): #euclidean rhythm generation
        try:
            numPulses = int(input("how many pulses? "))
        except ValueError:
            print("wrong.. numPuslses is now 9")
            numPulses = 9
            
        #does the user want rotatation input
        rotationInput = str(input("would you like to enter rotations? y/n "))
        if rotationInput != "y":
            print("that fine no rotation for you. ")

        rotation = [0,0,0]
        for i in range(3):
            instrumentnames = ["kick","snare","ride"]
            #===== numNotes user input =====
            try:
                numNotes = int(input(f"how many {instrumentnames[i]} notes? "))
            except ValueError:
                numNotes = random.randint(1,numPulses)
            if numNotes <0:
                numNotes *= -1
            #===== rotation User Input =====
            if (rotationInput == "y"):
                try:
                    print(f"the number of notes is now {numNotes}")
                    rotation[i] = int(input("input rotation.")) % numPulses
                except ValueError:
                    rotation[i] = 0
                if rotation[i] <0:
                    rotation[i] *= -1
                    print("Invalid input, setting rotation to 0.")    
                
            #based on code from ciskavriezenga's euclidean rhythm generator.
            sequence = []
            dur = int
            restValue = int
            
            dur = +int(numPulses/numNotes)
            sequence = [dur]*numNotes
            for o in range(numNotes):
                sequence[o] = dur 
                
            restValue = numPulses - (numNotes * dur)
            for u in range(round(restValue)):
                sequence[u]+= 1
                
            durations[i] = sequence.copy()
            print(f"{instrumentnames[i]}sequence: ", sequence)
        return (durations, rotation)
    durations, rotation = eucliRyGen(durations)
    


    initDur = [[],[],[]]
    stamps = [[],[],[]]


    def durationsToTimestamps16th(durations, rotation, quarterNoteDur):
        for i in range(len(durations)):
            #rotate rotations based on rotation variable.
            for o in rotation:
                durations[i].append(durations[i].pop(0))
            cumulative_timestamp = 0
            initDur[i] = durations[i].copy()
            for currentstamp in range(len(durations[i])):
                cumulative_timestamp += float((durations[i][currentstamp]) * quarterNoteDur)
                stamps[i].append(cumulative_timestamp)
        return stamps, initDur

    durationsToTimestamps16th(durations, rotation, quarterNoteDur)
    print("initial duration: ", initDur)



    #===== Generate events =====
    kickEvents = []
    snareEvents = []
    rideEvents = []
    def eventGen(stamps, initDur):
        velo = 80
        for i in range(len(stamps[0])):
            kickEvents.append({
                'timestamp': stamps[0][i],
                'duration': initDur[0][i],
                'instrumentName': "kick",
                'instrument': instruments[0][random.randint(0,1)],
                'velocity': velo
            })
        for i in range(len(stamps[1])):
            snareEvents.append({
                'timestamp': stamps[1][i],
                'duration': initDur[1][i],
                'instrumentName': "snare",
                'instrument': instruments[1][random.randint(0,4)],
                'velocity': velo
            })
        for i in range(len(stamps[2])):
            rideEvents.append({
                'timestamp': stamps[2][i],
                'duration': initDur[2][i],
                'instrumentName': "ride",
                'instrument': instruments[2],
                'velocity': velo
            })

    eventGen(stamps, initDur)
    totNumEvents = kickEvents + snareEvents + rideEvents




    # ===== playsample, sort eventtimestamps, midiExport, and handleevents =====


    def playSample(event):
        event['instrument'].play()
        print("playing ",event['instrumentName'])
        
    def getTimeStamp(totNumEvents):
        return totNumEvents['timestamp']
            
    def midiExport(bpm, quarterNoteDur, userFileName):
        track = 0
        channel = 9
        
        
        mf = MIDIFile(1)
        time_beginning = 0
        mf.addTrackName(track, time_beginning, "jazzDrumloop(WTDsequcent)")
        mf.addTempo(track, time_beginning, bpm)
        
        instMidiPitch = {
            "kick": 36,
            "snare": 38,
            "ride": 46
        }
        
        for event in totNumEvents:
            quarterNoteTime = event["timestamp"] / quarterNoteDur
            instrumentName = event["instrumentName"]
            mf.addNote(track,channel, instMidiPitch[instrumentName], quarterNoteTime, event["duration"], event["velocity"])
        # add user input file naming
        if userFileName:
            with open(f'csd2a/python_basics/Ffolder/midiOut/{userFileName}.midi','wb') as outf:
                mf.writeFile(outf)
        else:
            with open('csd2a/python_basics/Ffolder/midiOut/Whatadogsequencer.midi','wb') as outf:
                mf.writeFile(outf)
        print("file saved as", userFileName)
            
    
    def handleEvents(currentLoop, loops, totNumEvents):
        totNumEvents.sort(key=getTimeStamp)

        
        startTime = time.time()
        currentTime = time.time()
        increment = 0
        y = False
        while True:
            event = totNumEvents[increment]
            currentTime = time.time()
            #the total loop duration is calculated by taking last event and adding its duration times qnoteduration
            totLoopDur = totNumEvents[-1]['timestamp'] + (totNumEvents[-1]['duration'] * quarterNoteDur)
            if((currentTime - startTime) >= event['timestamp']):
                print("whattheloop: ", currentLoop+1)
                playSample(event)
                increment += 1
                #if the amount of samples played is equal to the totnumevents
                if(increment>=len(totNumEvents)):
                    time.sleep(totLoopDur - totNumEvents[len(totNumEvents)-1]['timestamp']) #add the last note length here
                    startTime = time.time()
                    increment = 0
                    currentLoop+=1
                    #i want to move the input away from here but doing so would cause the currentloop variable to no longer function as a trigger.
                    if(currentLoop >= loops):
                        if (input("would you like to repeat the loops? y/n ") == "y"):
                            startTime = time.time()
                            currentLoop = 0
                        elif (input("would you like to save midi file? y/n ") == "y"):
                            y = True
                            if y == True:
                                try:
                                    ufn = input("what filename would you like to save the midi file?: ")
                                    userFileName = ufn
                                except ValueError:
                                    print("wrong filename... whatadogsequencer.midi")
                                midiExport(bpm, quarterNoteDur, userFileName)
                                print("okbye")
                                break
                        else:
                            print("okbye")
                            break

                else:
                    time.sleep(0.001)
        
    handleEvents(currentLoop, loops, totNumEvents)
    

    prompt = input("would you like to run program again? ")
    #would you?