# source: https://clouddevs.com/python/libraries-for-audio-processing/
# NumPy & SciPy: Foundational Tools
## Reading and Plotting an Audio File
import numpy as np
import matplotlib.pyplot as plt
from scipy.io import wavfile
# Load audio file
sample_rate, audio_data = wavfile.read('sample_audio.wav')
# Plot audio waveform
plt.figure(figsize=(10, 4))
plt.plot(np.arange(len(audio_data)) / sample_rate, audio_data)
plt.xlabel('Time (s)')
plt.ylabel('Amplitude')
plt.title('Audio Waveform')
plt.show()

# Librosa: Music & Audio Analysis
## Extracting Mel-Frequency Cepstral Coefficients (MFCCs)
import librosa
import librosa.display
import matplotlib.pyplot as plt
# Load audio file
audio_file = 'sample_music.wav'
y, sr = librosa.load(audio_file)
# Extract MFCCs
mfccs = librosa.feature.mfcc(y=y, sr=sr)
# Display MFCCs
plt.figure(figsize=(10, 4))
librosa.display.specshow(mfccs, x_axis='time')
plt.colorbar(format='%+2.0f dB')
plt.title('MFCCs')
plt.show()

# soundfile: Reading and Writing Sound Files
## Reading and Writing Audio Files with soundfile
import soundfile as sf
# Read audio file
data, sample_rate = sf.read('input_audio.wav')
# Write audio file
sf.write('output_audio.wav', data, sample_rate)

# pydub: Simplifying Audio Manipulation
## Concatenating Audio Files with pydub
from pydub import AudioSegment
# Load audio files
audio1 = AudioSegment.from_file('audio1.wav')
audio2 = AudioSegment.from_file('audio2.wav')
# Concatenate audio files
combined_audio = audio1 + audio2
# Export concatenated audio
combined_audio.export('combined_audio.wav', format='wav')

# pyAudio: Real-time Audio Processing
## Recording and Playing Audio in Real-Time with pyAudio
import pyaudio
import numpy as np
# Initialize pyAudio
p = pyaudio.PyAudio()
# Open audio stream
stream = p.open(format=pyaudio.paFloat32, channels=1, rate=44100, input=True, output=True)
# Record and play audio in real-time
frames_per_buffer = 1024
for _ in range(100):
    audio_data = np.random.randn(frames_per_buffer).astype(np.float32)
    stream.write(audio_data.tobytes())
# Close the stream and terminate pyAudio
stream.stop_stream()
stream.close()
p.terminate()

# simpleaudio: Cross-platform Audio Playback
## Playing an Audio File with simpleaudio
import simpleaudio as sa
# Load audio file
wave_obj = sa.WaveObject.from_wave_file('sample_audio.wav')
# Play audio
play_obj = wave_obj.play()
play_obj.wait_done()

# audioread: Cross-format Audio Decoding
## Reading Audio Files with audioread
mport audioread
# Open audio file
with audioread.audio_open('audio_file.mp3') as f:
    print(f.channels, f.samplerate)
    for buf in f:
        process_audio_buffer(buf)

# madmom: Music Information Retrieval
## Beat Tracking with madmom
from madmom.features.beats import BeatTrackingProcessor, RNNBeatProcessor
from madmom.audio.signal import Signal
# Load audio signal
audio_signal = Signal('music_track.wav')
# Create beat tracking processor
beat_processor = BeatTrackingProcessor(fps=100)
# Track beats
beats = beat_processor(audio_signal)
print(beats)

# pyo: Audio Synthesis and Processing
## Creating an Audio Synthesis Patch with pyo
from pyo import *
# Initialize audio server
s = Server().boot()
# Create oscillator
oscillator = Sine(freq=440, mul=0.1)
# Start audio processing
oscillator.out()
# Sleep for 5 seconds
s.sleep(5)
# Stop audio processing
s.stop()

# TensorFlow and PyTorch: Deep Learning for Audio
## Sound Generation with a Neural Network in TensorFlow
import tensorflow as tf
# Define a simple generator model
generator = tf.keras.Sequential([
    tf.keras.layers.Dense(256, activation='relu', input_shape=(100,)),
    tf.keras.layers.Dense(512, activation='relu'),
    tf.keras.layers.Dense(1024, activation='relu'),
    tf.keras.layers.Dense(16384, activation='tanh'),
    tf.keras.layers.Reshape((128, 128, 1))
])
# Generate a sample sound
random_input = tf.random.normal((1, 100))
generated_sound = generator(random_input)
# Play the generated sound