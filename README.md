#CS389HW7

## To Use
To run the naive version of `convert_all`, run `make naive` and `./driver quotes.txt 1000`. To run the optimized version of the function,
run `make opt` and then `./driver_opt quotes.txt 1000` in the command line.

## Part1
We measured the time running `convert_all` with `atoi` is 0.04036s. With my naive implementation, running `convert_all` with my `stoi` takes only 0.016864s.
The reason for the performance boost is that atoi does not assume that the `char` array it is converting as numerical. Thus, it has to check if each character
is numerical, which takes time. In the mean time, my function simply assumes that each character is a number and convert it into an integer.

## Part2
### Prefetching
For `convert_all`, I prefetch the next element when I loop over `lines`, and for every quote in `lines`, I prefetch each character before accessing them.
The prefetching marks the data I fetch as read-only and disposable after it's accessed, which might have improved the cache utilization rate.
This brings the optimization down to around 0.015600s.

### `strlen`
Realizing that strlen takes linear time, I got rid of it, check if the current char is null to terminate the loop.
This cuts the run time to around 0.0075s, a 100% improvement.

### Cstring Access
Previously, I acess the each character in each quote using the `[]` operator which is a general accessor of array elements.
To improve the run time, I access elements by simply incrementing the pointer and dereferencing the pointer, which improves the 
run time to around 0.006760s, a 11% improvement. `[]` might be too general and need to access the size of a `char` in order to increment, thus slower.


