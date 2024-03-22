import numpy as np
import matplotlib.pyplot as plt
from scipy.signal import butter, lfilter

# Given parameters
fs = 5000  # Sampling frequency in Hz
f1 = fs / 10  # Frequency of the first component in Hz
f2 = fs / 5  # Frequency of the second component in Hz
n = 5000  # Number of points in the sequence
t = np.arange(n) / fs  # Time vector

# Generate the input sequence
x_n = np.cos(np.pi * t) + np.cos(2 * np.pi * t)

# Design the 3rd-order Butterworth filter with a cut-off frequency of 500 Hz
fc = 500  # Cut-off frequency in Hz
b, a = butter(N=3, Wn=fc/(fs/2), btype='low')

# Filter the sequence
y_n = lfilter(b, a, x_n)

# Compute the FFT of the input and output sequences
X_f = np.fft.fft(x_n)
Y_f = np.fft.fft(y_n)
frequencies = np.fft.fftfreq(n, 1/fs)

# Plot the magnitude of the FFT of the input and output sequences
plt.figure(figsize=(14, 7))
plt.subplot(2, 1, 1)
plt.plot(frequencies[:n//2], np.abs(X_f[:n//2]), label='Input')
plt.title('Frequency Components of the Input Sequence')
plt.xlabel('Frequency (Hz)')
plt.ylabel('Magnitude')
plt.grid(True)
plt.legend()

plt.subplot(2, 1, 2)
plt.plot(frequencies[:n//2], np.abs(Y_f[:n//2]), label='Output')
plt.title('Frequency Components after Filtering')
plt.xlabel('Frequency (Hz)')
plt.ylabel('Magnitude')
plt.grid(True)
plt.legend()
plt.tight_layout()
plt.show()
