
# !/usr/bin/python3
# Python example for an IIR combfilter.
# Pieter Suurmond, sept 6, 2019. (modified by Wouter Ensink, sept 7, 2020)
#
# Difference equation:  y[n] = x[n] + 0.5 y[n-6]
#
# Block diagram:        x ---> + -----------------------------------> y
#                              ^                          |
#                              |    -----------------     v
#                               ---| 6 samples delay |<-- x <-- 0.5
#                                   -----------------


from delay_line import DelayLine


# Class that acts as an infinite impulse response (IIR) combfilter:
class IIR_CombFilter:
    def __init__(self):
        # create delay line of 6 samples
        self.delay_line = DelayLine(num_samples=6)

    # each single input-sample (x) gives a single output-sample (y).
    def process_sample(self, input_sample):

        # read from delay line and calculate the output sample: y[n] = x[n] + 0.5 * y[n-6]
        # note that the * 0.5 was already done when the previous output sample was written to the delay line
        output_sample = input_sample + self.delay_line.read_sample()

        # write the output multiplied by 0.5 in the delay line, to be used 6 samples later...
        self.delay_line.write_sample(0.5 * output_sample)

        return output_sample


def print_impulse_response():
    iir_comb_filter = IIR_CombFilter()

    print('\nImpulse resonse for IIR Comb Filter:\n')

    for sample_index in range(-10, 25):
        # impulse is at sample index 0
        sample_in = 1.0 if sample_index == 0 else 0.0

        # process the input sample with the IIR filter
        sample_out = iir_comb_filter.process_sample(sample_in)

        # print the results
        print('sample_index: %4d: sample_in: %4.4f sample_out: %4.4f' % (sample_index, sample_in, sample_out))


if __name__ == '__main__':
    print_impulse_response()