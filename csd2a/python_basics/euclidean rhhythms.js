dur = 16 / 7
// calculate duration of a note, expressed in 16th
let num_notes = 7;
let num_pulses = 16
dur = num_pulses / num_notes


// fill list num_notes times with the duration value

let sequence = Array(num_notes)
for(i = 0; i < num_notes; i++) {
sequence[i] = dur
}

// calculate the rest value
// and distribute these amongst the stored durations

let rest_value = num_pulses - (num_notes * dur)
for(i = 0; i < rest_value; i++) {
 sequence[i] += 1
}
// TODO - Rotate!