"""
An example project in which three wav files are used.

------ EXERCISES ------

- What does the function wait_done() do?

- Answer the following question before running the code:
  Do you expect to hear the samples played simultaneously or one after the other?
  Why?
  
  i dont because of the wait.done functions after each block of code. 

- Alter the code:
  Play the sounds one after the other and then simultaneously.

- Alter the code:
  Ask the user to choice which one of the three samples should be played and
  only play the chosen sample.

- Give yourself a couple of assignments, like playing one of the samples ten
  times before the others are played, playing all samples a given number
  of times or playing the samples one after the other with 1 second between
  them.

"""

# simpleaudio is imported as sa -> shorter name
import simpleaudio as sa
import time

# load audio files
sampleHigh = sa.WaveObject.from_wave_file("python_basics/ciskavriezenga CSD_24-25 main blok2a/assignment_3/audioFiles/Pop.wav")
sampleMid = sa.WaveObject.from_wave_file("python_basics/ciskavriezenga CSD_24-25 main blok2a/assignment_3/audioFiles/Laser1.wav")
sampleLow = sa.WaveObject.from_wave_file("python_basics/ciskavriezenga CSD_24-25 main blok2a/assignment_3/audioFiles/Dog2.wav")

playAmount = 2


print("playSound.py. Samples loading")
for i in range(3):
  print("loading samples...")
  time.sleep(0.5)
print("samples [sampleHigh, sampleMid, sampleLow] LOADED")
print("loading sampler:")


match input("hi there, nice of you to come. which sample would you like this time?: "):
  case "sampleHigh":
      # play high sample
      sampleHighPlay = sampleHigh.play()
      sampleHighPlay.wait_done()
      
  case "sampleMid":
      # play high sample
      sampleMidPlay = sampleMid.play()
      sampleMidPlay.wait_done()
      
  case "sampleLow":
      # play high sample
      sampleLowPlay = sampleLow.play()
      sampleLowPlay.wait_done()
  case _:
    print("doodookaka")

    
  


for i in range(playAmount): #coincidental playback and back to back
  # match i + 1:
    # case 1:
      # print("coincident")
      # # play high sample
      # sampleHighPlay = sampleHigh.play()
      # # play mid sample
      # sampleMidPlay = sampleMid.play()
      # # play low sample
      # sampleLowPlay = sampleLow.play()
      # sampleLowPlay.wait_done()
      # time.sleep(1)
    # case 2:
    #   print("seperate")
      # play high sample
      sampleHighPlay = sampleHigh.play()
      # wait till sample is done playing
      sampleHighPlay.wait_done()

      # play mid sample
      sampleMidPlay = sampleMid.play()
      # wait till sample is done playing
      sampleMidPlay.wait_done()

      # play low sample
      sampleLowPlay = sampleLow.play()
      # wait till sample is done playing
      sampleLowPlay.wait_done()


      

