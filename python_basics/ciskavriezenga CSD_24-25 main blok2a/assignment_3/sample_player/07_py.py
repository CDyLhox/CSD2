
import simpleaudio as sa
import time
import random

# load 1 audioFile and store it into a list
# note: using a list taking the next step into account: using multiple samples
samples = [sa.WaveObject.from_wave_file("python_basics/ciskavriezenga CSD_24-25 main blok2a/assignment_3/audioFiles/Pop.wav"), 
           sa.WaveObject.from_wave_file("python_basics/ciskavriezenga CSD_24-25 main blok2a/assignment_3/audioFiles/Laser1.wav")]

bpm = 120
quarterNoteDuration = 60 / bpm
# calculate the duration of a sixteenth note
sixteenthNoteDuration = quarterNoteDuration / 4.0

# create a list to hold the timestamps
timestamps = []

# create a list with 'note timestamps' specified as 16th notes, indicating
# the time at which the sample must be played
timestamps16th = [0, 2, 4, 8, 11]

loops = 4

for loop_number in range(1, loops + 1):
      print(f"Starting loop {loop_number}/{loops}")
      # transform the sixteenthTimestamps to a timestamps list with time values
      for timestamp in timestamps16th:
        timestamps.append(timestamp * sixteenthNoteDuration)


      # retrieve the first timestamp
      # NOTE: pop(0) returns and removes the element at index 0
      timestamp = timestamps.pop(0)

      # retrieve the startime: current time
      startTime = time.time()


      # play the sequence
      while True:
        # retrieve current time
        currentTime = time.time()

        # check whether the current time is beyond the timestamp's time,
        # meaning it is time to play the sample
        if(currentTime - startTime >= timestamp):
          print("hoi")
          random_sample = random.choice(samples)
          random_sample.play()

          # if there are timestamps left in the timestamps list
          if timestamps:
            # retrieve the next timestamp
            timestamp = timestamps.pop(0)
          else:
            # list is empty, stop the loop
            break
        else:
          # short wait to prevent we'll keep the processor busy when there's
          # nothing to do
          time.sleep(0.001)


time.sleep(1) # let the last 'note' ring out