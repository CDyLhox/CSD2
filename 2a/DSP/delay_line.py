# Written by Wouter Ensink, sept 7, 2020.

# Helper class to abstract away the delay line
class DelayLine:
    def __init__(self, num_samples):
        self.size = num_samples
        self.buffer = [0.0] * self.size
        self.current_index = 0

    def read_sample(self):
        return self.buffer[self.current_index]

    # when writing a sample, it also moves the index one ahead
    def write_sample(self, value):
        self.buffer[self.current_index] = value
        self.current_index += 1
        self.current_index %= self.size