
# !/usr/bin/python3
# Python example for a FIR combfilter.
# Pieter Suurmond, sept 6, 2019. (modified by Wouter Ensink, sept 7, 2020)
#
# Difference equation:  y[n] = x[n] + x[n-8]
#
# Block diagram:                 -----------------
#                       x ----->| 8 samples delay |----> + ---> y
#                           |    -----------------       ^
#                           |                            |
#                            ----------------------------


from delay_line import DelayLine


# Class that acts as a finite impulse response (FIR) combfilter:
class FIR_CombFilter:
    def __init__(self):
        # create a delay line of 8 samples
        self.delay_line = DelayLine(num_samples=8)

    # each single input-sample (x) gives a single output-sample (y).
    def process_sample(self, input_sample):

        # Read earlier input (8 samples ago) from delay line and calculate the output: y[n] = x[n] + x[n-8]
        output_sample = input_sample + self.delay_line.read_sample()

        # put the input sample in the delay line and advance its index
        self.delay_line.write_sample(input_sample)

        return output_sample


def print_impulse_response():
    fir_comb_filter = FIR_CombFilter()

    print('\nImpulse resonse for FIR Comb Filter:\n')

    for sample_index in range(-10, 21):
        # impulse is at sample index 0
        sample_in = 1.0 if sample_index == 0 else 0.0

        # process the input sample with the FIR filter
        sample_out = fir_comb_filter.process_sample(sample_in)

        # print the results
        print('sample_index: %4d: sample_in: %4.4f sample_out: %4.4f' % (sample_index, sample_in, sample_out))


if __name__ == '__main__':
    print_impulse_response()