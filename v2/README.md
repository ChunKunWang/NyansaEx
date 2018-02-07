# A daily URLs hit count: Version 2

Author: Chun-Kun Wang

E-mail: wckamos@gmail.com

## Changes

In version one, we convert *string* key to *long* key in order to get better performance. Version two discarded the key type conversion and just used *sting* as key. Based on the experiment, the implementation with *string* key has better performance.

## Experiment

v1: the version with the conversion from *string* key to *long* key

v2: the version without the conversion

Input file: 213,480 Lines in total

Sampel output:

classroom(93)% time ./urlSummary ./test.txt
08/08/2014 GMT
www.google.com 35580
www.facebook.com 35568
news.ycombinator.com 17784
08/09/2014 GMT
www.nba.com 53376
sports.yahoo.com 35580
www.cnn.com 17796
08/10/2014 GMT
www.twitter.com 17796
0.244u 0.232s 0:00.47 100.0%    0+0k 0+0io 0pf+0w

### Experiment results

|     | v1 (s) | v2 (s) |
|-----|--------|--------|
| 1   | 0.216  | 0.2    |
| 2   | 0.188  | 0.188  |
| 3   | 0.212  | 0.184  |
| 4   | 0.208  | 0.204  |
| 5   | 0.164  | 0.208  |
| 6   | 0.16   | 0.188  |
| 7   | 0.224  | 0.244  |
| 8   | 0.204  | 0.22   |
| 9   | 0.216  | 0.184  |
| 10  | 0.232  | 0.16   |
| AVG | 0.2024 | 0.198  |

