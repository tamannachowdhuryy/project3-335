# project3-335

For project 3, you will find the 25th, 50th, and 75th %ile in a list of integers randomly sampled from a gamma distribution. Importantly, as the input size increases, the number of unique values will grow slowly, and there will be an increasing number of duplicates.
You will do this in 4 ways, and benchmark the time taken for each method:
1) Using std::sort
2) Using quickselect 3 times, once for each %ile
3) Modifying quickselect to recurse if any of the 3 values are in the subrange
4) Using a modified counting sort that uses hashes
Because there will be many duplicates, counting sort seems like a good choice. However, since a gamma distribution has no upper limit, we must use the modification of counting sort that uses hashes.
