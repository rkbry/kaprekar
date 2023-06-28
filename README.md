# kaprekar
A simple program to determine which four-digit integers reach Kaprekar's constant in a single step, *i.e.*, if a four-digit
number reordered ascending is subtracted from the same number reorded descending, the result is Kaprekar's constant, **6174**.

See [https://en.wikipedia.org/wiki/6174](https://en.wikipedia.org/wiki/6174) for more information.

## TODO
Splitting a four-digit number into an array is done twice-- which is repetitive. So are the helper comparison functions
written for `qsort()`. Not sure how I fix the latter, but for the former, I'll write a `split()` function possibly.

*NOTE:* I am a hobbyist and my coding skills are **weak** so maybe view this repo as an example of *what not to do.*
