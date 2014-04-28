clear all;
function ret = func(t)
    ret = sin(30 * pi * t / 64) + sin(4 * pi * t / 64);
    endfunction
t = linspace(0, 63, 64);
valuesC = func(t);
plot(t, valuesC) 
fourier = fftshift(fft(valuesC));
filtered = fourier' .* hamming(64)';
fourierResult = fftshift(filtered);
plot(real(ifft(fourierResult)))
