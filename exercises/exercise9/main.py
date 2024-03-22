import numpy as np
import matplotlib.pyplot as plt
from scipy.signal import butter, freqz

# Parameters for both filters
fc = 1000  # Cut-off frequency in Hz
fs = 5000  # Sampling frequency in Hz
order = 3  # Order of the Butterworth filter

# Analog Butterworth filter frequency response
w_analog = np.logspace(0, np.log10(fc * 10), 1000)  # Wider range for better visualization
H_analog = 1 / np.sqrt(1 + (w_analog / fc)**(2 * order))

# Digital Butterworth filter design using Bilinear Transformation
b, a = butter(order, fc / (fs / 2), btype='low', analog=False)
w_digital, h_digital = freqz(b, a, worN=8000)

# Normalize frequency axis for digital filter to Hz for comparison
f_digital = w_digital * fs / (2 * np.pi)

# Plotting
plt.figure()
plt.semilogx(w_analog, 20 * np.log10(H_analog), label='Analog 3rd Order Butterworth LPF')
plt.semilogx(f_digital, 20 * np.log10(np.abs(h_digital)), label='Digital 3rd Order Butterworth LPF')
plt.title('Magnitude Frequency Response')
plt.xlabel('Frequency (Hz)')
plt.ylabel('Magnitude (dB)')
plt.grid(which='both', linestyle='-', linewidth='0.5')
plt.legend()
plt.show()
