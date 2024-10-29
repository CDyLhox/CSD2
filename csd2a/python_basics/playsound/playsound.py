import simpleaudio as sa
import time

a = int(0)


wave_obj = sa.WaveObject.from_wave_file('/Users/dylan/Cage/CageDotLog/CSD2/python_basics/sample/[weirdloop].wav')

playamount = int(input("how many times do you want the audio to play?: "))
print(playamount)


for delay in range(playamount):
    print(delay)
        
    print(f"Playing sound {delay + 1} out of {playamount}")
        
    play_obj = wave_obj.play()
    time.sleep(delay)


        
play_obj.wait_done()



