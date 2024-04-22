# project3-335

For project 3, given an input file of integer values, you will compute all the statistics included in a five-number summary or a box plot: the minimum value, the 25th, 50th, and 75th percentiles, and the maximum value.
The integers in the input will be sampled from a gamma distribution. Because of the characteristics of gamma distributions, as the input size increases, the number of unique values will grow slowly, and there will be an increasing number of duplicates, yet there is no absolute upper limit on the values. This will make the input a good candidate for a hash-based counting sort.
You will compute the five-number summary with each of the following methods, and benchmark the time taken for each method:
1) Use std::sort
2) Use quickselect 3 times, then calculate the min and max separately
3) Modify quickselect to recurse if any of the 5 values are in the subrange
4) Use a modified counting sort that uses hashes
For method 2, find the median first. Then, on the same vector that's already partitioned around the median, call quickselect on the left half to find P25 and on the right half to find P75. Then, search the part of the vector below P25 for the min and above P75 for the max.
For method 3, modify quickselect's recursive function to take a short list of positions rather than just one. If you refer to p.322 in the textbook, you can replace int k with a small vector or list. Then rewrite the recursive portion so that quickselect calls itself on one or both sides, depending on whether there are positions you're searching for on both sides or only one.