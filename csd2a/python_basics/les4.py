import simpleaudio as sa
import time

kick = sa.WaveObject.from_wave_file('/Users/dylan/Cage/CageDotLog/CSD2/python_basics/sample/[weirdloop].wav')
snare = sa.WaveObject.from_wave_file('/Users/dylan/Cage/CageDotLog/CSD2/python_basics/sample/[weirdloop].wav')

pieter = {'name': 'pieter', 'age': 23},
marc = {'name': 'marc', 'age': 23},
ciska = {'name': 'ciska', 'age': 23}

teachers = [pieter, marc, ciska]
            #je hebt straks 3 lijsten, die kan je samenvoegen tot 1 lijst. 
            #dan daarna kan je een sort algoritme gebruiken om de timestamps op volgorde te zetten om de sequence te generen 
            # als je 2 lijsten wilt combineren dan +
            #maak het in een forloop (zie exervcise dictionary generation function)

kick_event = {
    'timestamp': 1000,
    'instrument_name': 'kick',
    'instrument': kick,
    'velocity': 1
}
snare_event = {
    'timestamp': 2000,
    'instrument_name': 'snare',
    'instrument': snare,
    'velocity': 2
}

def handle_event(event):
    print(event['timestamp'])
    print(event['instrument'])
    event['instrument'].play()
    print(event['velocity'])
    
