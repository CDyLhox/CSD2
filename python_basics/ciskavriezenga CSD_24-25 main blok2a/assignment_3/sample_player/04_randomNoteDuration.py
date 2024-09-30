"""
An example project in which three .wav files are played after the other with a
break in between of a random note duration.
Used note durations are: sixteenth, eight, quarter notes

------ EXERCISES ------
- Answer the following questions before running the code:
  - How many different samples will be played?
    3 different samples because of the for sample in samples: sample.play()
  - How many times a sample will be played?
    4 x 3 want er is een for loop onderaan die range 4 gebruikt en in de playsample functie speelt hij samples voor de hoeveelheid samples die er zijn
  - How many seconds will there be in between the playback of samples? (3 answers)
  1800ms 
  3600ms
  7200ms
  
  its all so clear now, i did the quarternote times the bpm instaid of doing it /
  
  Check your answers by running the code.

- Alter the code:
  Write a function which returns a list with time intervals based on two
  arguments:
  - the bpm
  - a list of note durations
  Use this function.
"""

import simpleaudio as sa
import time
import random

#load audio files into a list
samples = [sa.WaveObject.from_wave_file("python_basics/ciskavriezenga CSD_24-25 main blok2a/assignment_3/audioFiles/Pop.wav"),
              sa.WaveObject.from_wave_file("python_basics/ciskavriezenga CSD_24-25 main blok2a/assignment_3/audioFiles/Laser1.wav"),
              sa.WaveObject.from_wave_file("python_basics/ciskavriezenga CSD_24-25 main blok2a/assignment_3/audioFiles/Dog2.wav")]

# create a list with possible note durations: sixteenth, eighth and a quarter note
noteDurations = [0.25, 0.5, 1]
bpm = int(input("what bpm do you want?: "))
# create a list to hold timeIntervals
timeIntervals = []

# transform noteDurations into timeIntervals, depending on bpm
# calculate quarterNote in seconds (duration of a quarter note)


# display timeIntervals

def timeInts(bpm, noteDurations):
  quarterNote = 60.0 / bpm
  for noteDuration in noteDurations:
    # calculate timeDuration and add to the list
    timeIntervals.append(quarterNote * noteDuration)
    print("Selection of time intervals: ", timeIntervals )
    
timeInts(bpm, noteDurations)
# a function that plays a list of samples with random timeIntervals in between,
# based on the values in the passed in interval list.
def playSamples(samples, intervals):
  # play samples and wait in between (random duration)
  for sample in samples:
    sample.play()
    # retrieve a random timeInterval
    # use the random.choice function -> returns a random element from a sequence
    timeInterval = random.choice(intervals)
    print("waiting: " + str(timeInterval) + " seconds.")
    time.sleep(timeInterval)
    
  
  

# call the playSamples function 4 times
for i in range(4):
  playSamples(samples, timeIntervals)

