cdlzero@cdlzero:~$ cat sendSlider.py     
import time
import board
import busio
from adafruit_ads1x15.ads1115 import ADS1115
from adafruit_ads1x15.analog_in import AnalogIn
from pythonosc.udp_client import SimpleUDPClient

HOST = "100.81.145.70"
PORT = 7777
PATHOSC = "/parameter"

i2c = busio.I2C(board.SCL, board.SDA)
ads = ADS1115(i2c)
chan = AnalogIn(ads, 0)

client = SimpleUDPClient(HOST, PORT)

MAX_OBSERVED = 0.804

while True:
    raw = chan.value
    norm = raw / 32767.0
    mapped = norm / MAX_OBSERVED

    if mapped > 1.0:
        mapped = 1.0

    client.send_message(PATHOSC, float(mapped))
    print(raw, mapped)
    time.sleep(0.05)
cdlzero@cdlzero:~$ 
