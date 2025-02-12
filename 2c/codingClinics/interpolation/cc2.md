* `nnMap(value, low, high)`
  27   │   _returns the nearest-neighbour value of the passed value within the g
       │ iven range_
  28   │     * value: a normalized value within range [0, 1]
  29   │     * low: the lower bound of the range
  30   │     * high: the upper bound of the range
  31   │ 
  32   │ * `linMap(value, low, high)`
  33   │   _returns the linearly interpolated value of the passed value within t
       │ he given range_
  34   │     * value: a normalized value within range [0, 1]
  35   │     * low: the lower bound of the range
  36   │     * high: the upper bound of the range
  37   │ 
  38   │ * `mapInRange(value, fromLow, fromHigh, toLow, toHigh)`
  39   │   _returns the mapped value from one range to another_
  40   │     * fromLow: the lower bound of the value’s current range.
  41   │     * fromHigh: the upper bound of the value’s current range.
  42   │     * toLow: the lower bound of the value’s target range.
  43   │     * toHigh: the upper bound of the value’s target range.
