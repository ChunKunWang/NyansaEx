# A daily URLs hit count: Version 4

Author: Chun-Kun Wang

E-mail: wckamos@gmail.com

## Changes

Based on the statement - the cardinality of hit count values and the number of days are much smaller than the number of unique URLs -, we optimize our porgram not only by replacing *map* into *unordered_map* but also adopting bucketsort instead of built-in *sort* function. This version has O(N) time complexity and O(N) space complexity. According to our experiment results, this version is the fastest one. 

## Time Complexity

The total time complexity of building hash table is O(N) because of O(1) of *unordered_map* insertion.

Sorting url outcomes can be broken down into two parts. First, *map* is used to sort table by date. This step takes O(K*log K) where K is the number of days. Secondly, we optimize the work of sorting by hit count values from O(N*log N) to O(N). We discard the implementation of built-in *sort* function and use bucketsort algorithm, which is O(N). Hence, the total time complexity of sorting is O(K*log K + N).

According to the cardinality, the number of days are much smaller than the number of unique URLs so we can ignore it. Finally, the time complexity of our program is O(N + K*log K + N) = O(N). 

## Space Complexity

The underlying data structure of *unordered_map* is open hash, which means an array of buckets. In the worst case, the space complexity of *unordered_map* is O(N). That means, for every line, it requires a new entry. On the other hand, sorting needs space of bucksort and *vector* so all the space they need is O(N). Hence, the total space complexity is O(N + N) = O(N).

## Experiment

v1: *map*, *long* key, built-in *sort*

v2: *map*, *string* key, built-in *sort*

v3: *unordered_map*, *string* key, built-in *sort*

v4: *unordered_map*, *string* key, bucketsort

Input file: 213,480 Lines in total

Run: run 10 times and have an average

### Experiment results

|     | v1 (s) | v2 (s) | v3 (s) | v4 (s) |
|-----|--------|--------|--------|--------|
| 1   | 0.216  | 0.2    | 0.2    | 0.192  |
| 2   | 0.188  | 0.188  | 0.192  | 0.172  |
| 3   | 0.212  | 0.184  | 0.18   | 0.196  |
| 4   | 0.208  | 0.204  | 0.192  | 0.184  |
| 5   | 0.164  | 0.208  | 0.144  | 0.172  |
| 6   | 0.16   | 0.188  | 0.208  | 0.164  |
| 7   | 0.224  | 0.244  | 0.196  | 0.192  |
| 8   | 0.204  | 0.22   | 0.18   | 0.208  |
| 9   | 0.216  | 0.184  | 0.2    | 0.172  |
| 10  | 0.232  | 0.16   | 0.18   | 0.188  |
| AVG | 0.2024 | 0.198  | 0.1872 | 0.184  |

