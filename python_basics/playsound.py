import simpleaudio as sa
import time

a = int(0)

wave_obj = sa.WaveObject.from_wave_file('python_basics/sample/[weirdloop].wav')
# wave_obj = sa.WaveObject.from_wave_file('python_basics/sample/[weirdloop]120.wav')
# wave_obj = sa.WaveObject.from_wave_file('/Users/dylan/Cage/CageDotLog/CSD2/python_basics/sample/Gas.wav')


playamount = int(input("how many times do you want the audio to play?: "))
# play_obj = wave_obj.play()

def Playsample(playamount):
    for x in range(playamount):
        print(f"Playing sound {x + 1} out of {playamount}")
        play_obj = wave_obj.play()
        time.sleep(1)
        #play_obj.wait_done()
        
        # if play_obj.is_playing() == False:
        #     play_obj = wave_obj.play()
        # elif play_obj.is_playing() == True:
        #     print(x + 1)


Playsample(playamount)

