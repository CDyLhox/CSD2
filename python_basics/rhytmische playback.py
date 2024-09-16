import simpleaudio as sa
import time

a = int(0)
num_playback = []
playbacktime = []
playloop = int
preset = []

with open("python_basics/rhytminput","r") as file:
    preset = file.readlines()
    
wave_obj = sa.WaveObject.from_wave_file('/Users/dylan/Cage/CageDotLog/CSD2/python_basics/sample/[weirdloop].wav')


num_playback = (input("how many times do you want the audio to play?: "))
# in case the user specifies preset1 use rhytminput.txt
if num_playback == "preset1":
    num_playback = int(preset[0])
    bpm = 60/int(preset[1])
    playloop = int(preset[2])
    for x in range(num_playback):
        playbacktime.append(float(preset[(x)+3]))
# if not then make the num_playback into an int and ask for user input
else:
    num_playback = int(num_playback)
    bpm = 60/(int(input("and what bpm would you like? ")))
    playloop = int(input("how many times to loop? "))
    for x in range(num_playback):
        playbacktime.append(float(input(f"time before sample {x+ 2} ")))

for y in range(playloop):
    for x in range(num_playback):
        play_obj = wave_obj.play()
        print(f"loop {y+1} sample {x+1}")
        time.sleep(playbacktime[x] * bpm)
    




