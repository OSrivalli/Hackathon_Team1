// audio.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
	/*% Simple DCT compression.
		% Works in matlab with signal processing toolbox or octave.
		% X : (audio)samples, vector with each element in[-1, 1]
		% window : window size, length(X) must be divisible by this.
		% num_components : number of DCT components to store per window.
		% coeff_bits : number of bits to use to store each coefficient.*/
		function result = compress_dct(X, window, num_components, coeff_bits)
		num_win = length(X) / window;
	X = reshape(X, window, num_win); // reshape so each window is a row
		Y = dct(X); // applies dct to each row

		// find top components and their indices
		[a, I] = sort(abs(Y), 'descend');
	I = I(1:num_components, : );

	// build struct
		result.coeffs = int16(zeros(num_components, num_win));
	result.ind = int16(I);
	result.window = window;
	result.coeff_bits = coeff_bits;
	for i = 1:num_win
		// store each coefficient(in[-1, 1]) as an integer mapped to range
		// (-2 ^ (coeff_bits - 1), 2 ^ (coeff_bits_1))
		result.coeffs(:, i) = int16(Y(I(:, i), i) * 2 ^ (coeff_bits - 1));
	end
		end



		function X = decompress_dct(data)
		num_win = size(data.coeffs, 2);
	coeffs = double(data.coeffs) / (2 ^ (data.coeff_bits - 1)); // Rescale coeffs to[-1, 1]
		// Construct full DCT windows from sparse.
		Y = zeros(data.window, num_win);
	for i = 1:num_win
		Y(data.ind(:, i), i) = coeffs(:, i);
	end

		// Inverse DCT each window.
		X = idct(Y);
	// Stitch windows into one long vector.
		X = reshape(X, num_win*data.window, 1);
	end
	return 0;
}

