# A daily URLs hit count: Version 3

Author: Chun-Kun Wang

E-mail: wckamos@gmail.com

## Changes

Based on the statement - the cardinality of hit count values and the number of days are much smaller than the number of unique URLs -, we optimize our porgram by replacing *map* into *unordered_map* and also adopting *string* key. According to our experiment results, this version is the fastest one.

Note: v4 has an optimized version and runs faster than this version.

## Time Complexity

Unlike *map* taking O(log N) to insert, the insertion of *unordered_map* has O(1) in average case. Since we have N number of input lines, the total time complexity of building hash table is O(N).

Secondly, sorting the hash table for outout takes extra effort. We used *sort* function and *map* for sorting, so we have O(N*log N) time complexity.

Finally, the time complexity of our program is O(N + N*log N) = O(N*log N). In terms of time complexity, sorting for output is the bottleneck in our program. 

## Space Complexity

The underlying data structure of *unordered_map* is open hash, which means an array of buckets. In the worst case, the space complexity of *unordered_map* is O(N). That means, for every line, it requires a new entry. On the other hand, sorting needs space of *sort* and *vector* so all the space they need is O(N). Hence, the total space complexity is O(N + N) = O(N).

## Experiment

v1: *map*, *long* key

v2: *map*, *string* key

v3: *unordered_map*, *string* key

Input file: 213,480 Lines in total

Run: run 10 times and have an average

### Experiment results

|     | v1 (s) | v2 (s) | v3 (s) |
|-----|--------|--------|--------|
| 1   | 0.216  | 0.2    | 0.2    |
| 2   | 0.188  | 0.188  | 0.192  |
| 3   | 0.212  | 0.184  | 0.18   |
| 4   | 0.208  | 0.204  | 0.192  |
| 5   | 0.164  | 0.208  | 0.144  |
| 6   | 0.16   | 0.188  | 0.208  |
| 7   | 0.224  | 0.244  | 0.196  |
| 8   | 0.204  | 0.22   | 0.18   |
| 9   | 0.216  | 0.184  | 0.2    |
| 10  | 0.232  | 0.16   | 0.18   |
| AVG | 0.2024 | 0.198  | 0.1872 |

