#!!!!!!!!!!!!!DISCLAIMER: code by chatgpt!!!!!!!!!!!!!!!!
import os
from pydub import AudioSegment
from vosk import Model, KaldiRecognizer
import json
import spacy

# Load the spaCy Dutch language model
nlp = spacy.load("nl_core_news_sm")

# Define the paths for the audio file and the output folders
audio_file_path = "/Users/dylan/Cage/Interviews/NORMAL/1monozo.wav"
output_base_folder = "/Users/dylan/Cage/1AUDIOCATN/pos_categorised_zoe"

# Load your Vosk model (make sure it's downloaded)
model = Model("/Users/dylan/Cage/CageDotLog/LANGMODEL/vosk-model-small-nl-0.22")

# Transcribe the audio with word-level timestamps
def transcribe_audio_with_timestamps(audio_file):   
    audio = AudioSegment.from_wav(audio_file)  # Load audio file
    recognizer = KaldiRecognizer(model, audio.frame_rate)
    recognizer.SetWords(True)  # Enable word-level timestamps

    transcript = []
    buffer_size = 4000  # Larger buffer size
    for i in range(0, len(audio), buffer_size):
        segment = audio[i:i + buffer_size]
        if recognizer.AcceptWaveform(segment.raw_data):
            result = json.loads(recognizer.Result())
            transcript.append(result)
            print(f"Currently at: {result}")

    # Process the final result
    final_result = json.loads(recognizer.FinalResult())
    transcript.append(final_result)

    # Print the transcript to check its structure
    print(json.dumps(transcript, indent=4))

    return transcript

# Save the transcribed text to a .txt file
def save_transcript_to_txt(transcript, audio_file):
    # Extract the base name of the audio file (without extension)
    base_name = os.path.splitext(os.path.basename(audio_file))[0]
    txt_file_path = os.path.join(output_base_folder, f"{base_name}.txt")

    # Collect the transcribed text
    transcribed_text = ""
    for result in transcript:
        if 'text' in result:
            transcribed_text += result['text'] + " "

    # Write the text to a .txt file
    with open(txt_file_path, "w") as txt_file:
        txt_file.write(transcribed_text.strip())

    print(f"Transcription saved to {txt_file_path}")

# Tag each word with its part of speech (POS) and categorize by POS or "etc"
def categorize_audio_by_pos_or_etc(transcript, audio_file):
    audio = AudioSegment.from_wav(audio_file)  # Load the full audio
    for result in transcript:
        if 'result' in result:  # Ensure there are recognized words
            for word_data in result['result']:
                word = word_data.get('word', None)
                start_time = word_data.get('start', None)
                end_time = word_data.get('end', None)

                if word and start_time is not None and end_time is not None:
                    # Process the word through spaCy to get POS tag
                    doc = nlp(word)
                    pos_tag = doc[0].pos_  # Get the POS tag (e.g., 'NOUN', 'VERB', 'ADJ')

                    # Extract the audio segment for this word
                    start_time_ms = start_time * 1000  # Convert to milliseconds
                    end_time_ms = end_time * 1000  # Convert to milliseconds
                    word_audio = audio[start_time_ms:end_time_ms]

                    # Create a folder for the POS category if it doesn't exist
                    pos_folder = os.path.join(output_base_folder, pos_tag)
                    os.makedirs(pos_folder, exist_ok=True)

                    # Save the word audio file in its respective POS folder
                    output_file_path = os.path.join(pos_folder, f"{word}_{start_time_ms}.wav")
                    word_audio.export(output_file_path, format="wav")

        # Handle unrecognized sounds or non-speech segments
        else:
            start_time = result.get('start', None)
            end_time = result.get('end', None)
            if start_time is not None and end_time is not None:
                # Extract the non-speech sound or "etc" segment
                start_time_ms = start_time * 1000  # Convert to milliseconds
                end_time_ms = end_time * 1000  # Convert to milliseconds
                etc_audio = audio[start_time_ms:end_time_ms]

                # Create the "etc" folder for non-speech segments
                etc_folder = os.path.join(output_base_folder, "etc")
                os.makedirs(etc_folder, exist_ok=True)

                # Save the non-speech audio segment in the "etc" folder
                output_file_path = os.path.join(etc_folder, f"non_speech_{start_time_ms}.wav")
                etc_audio.export(output_file_path, format="wav")

# Main function to process the audio file
def process_audio_file(audio_file_path):
    transcript = transcribe_audio_with_timestamps(audio_file_path)
    categorize_audio_by_pos_or_etc(transcript, audio_file_path)
    save_transcript_to_txt(transcript, audio_file_path)

# Run the process
process_audio_file(audio_file_path)




# # Tag each word with its part of speech (POS) and categorize by POS
# def categorize_audio_by_pos(transcript, audio_file):
#     audio = AudioSegment.from_wav(audio_file)  # Load the full audio
#     for result in transcript:
#         if 'result' in result:  # Ensure there are recognized words
#             for word_data in result['result']:
#                 word = word_data.get('word', None)
#                 start_time = word_data.get('start', None)
#                 end_time = word_data.get('end', None)

#                 if word and start_time is not None and end_time is not None:
#                     # Process word through spaCy to get POS tag
#                     doc = nlp(word)
#                     pos_tag = doc[0].pos_  # Get the POS tag (e.g., 'NOUN', 'VERB', 'ADJ')

#                     # Extract the audio segment for this word
#                     start_time_ms = start_time * 1000  # Convert to milliseconds
#                     end_time_ms = end_time * 1000  # Convert to milliseconds
#                     word_audio = audio[start_time_ms:end_time_ms]

#                     # Create a folder for the POS category if it doesn't exist
#                     pos_folder = os.path.join(output_base_folder, pos_tag)
#                     os.makedirs(pos_folder, exist_ok=True)

#                     # Save the word audio file in its respective POS folder
#                     output_file_path = os.path.join(pos_folder, f"{word}_{start_time_ms}.wav")
#                     word_audio.export(output_file_path, format="wav")

# # Main function to process the audio file
# def process_audio_file(audio_file_path):
#     transcript = transcribe_audio_with_timestamps(audio_file_path)
#     categorize_audio_by_pos(transcript, audio_file_path)

# # Run the process
# process_audio_file(audio_file_path)