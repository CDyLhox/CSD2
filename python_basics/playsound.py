import simpleaudio as sa
import time

a = int(0)

wave_obj = sa.WaveObject.from_wave_file('python_basics/sample/[weirdloop]120.wav')


playamount = int(input("how many times do you want the audio to play?: "))

def Playsample(playamount):
    for x in range(playamount):
        print(f"Playing sound {x + 1}")
        # play_obj.wait_done()
        play_obj = wave_obj.play()

        if play_obj.is_playing() == 0:
            play_obj = wave_obj.play()
        elif play_obj.is_playing() == 1:
            print(x + 1)


Playsample(playamount)

