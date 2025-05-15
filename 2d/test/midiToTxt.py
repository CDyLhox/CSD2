from mido import MidiFile
import sys
import math

def midi_to_freq(note):
    """Convert MIDI note number to frequency in Hz."""
    return round(440.0 * (2 ** ((note - 69) / 12.0)), 2)

def midi_to_txt(midi_path, txt_output_path):
    mid = MidiFile(midi_path)
    time_cursor = 0
    notes = []

    for track in mid.tracks:
        time_cursor = 0
        for msg in track:
            time_cursor += msg.time
            if msg.type == 'note_on' and msg.velocity > 0:
                freq = midi_to_freq(msg.note)
                notes.append((time_cursor, freq))
                time_cursor = 0
            elif msg.type == 'note_off' or (msg.type == 'note_on' and msg.velocity == 0):
                notes.append((time_cursor, 0))
                time_cursor = 0

    with open(txt_output_path, 'w') as f:
        for duration, freq in notes:
            f.write(f"{freq},{duration}\n")

if __name__ == "__main__":
    # Example usage
    midi_path = "../motifs-Flute.mid"
    txt_output_path = "motifs-Flute.txt"
    midi_to_txt(midi_path, txt_output_path)
    print(f"Saved output to {txt_output_path}")

