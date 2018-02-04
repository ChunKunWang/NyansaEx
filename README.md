# A daily URLs hit count

Author: Chun-Kun Wang

E-mail: wckamos@gmail.com

## Problem

1. Produce a daily summarized report on url hit count, organized daily (use GMT) with the earliest date appearing first.

2. Display the number of times each url is visited in the order of highest hit count to lowest count.

3. Assume that the cardinality of hit count values and the number of days are much smaller than the number of unique URLs.

4. Assume that number of unique URLs can fit in memory.

## Discussion

1. I decide to adopt *map* because it keeps the date of entries ordered. 

2. The reason why I don't choose *unordered_map* is because of memory usage. *unordered_map* usually consumes more memory than *map* does. The other point is the worst case complexity. Although *unordered_map* provides **O(1)** lookup-retrieval, lookup may raise to **O(N)** if the collision of entry occured. We already knew the number of days are much smaller than the number of URLs. In contrast, *map* always keeps lookup-retrieval as **O(log N)**.

3. I used date as the key to *map*. Considering performance issue, a *string* of date is transformed as *long* because a *string* key will cause an additional memory allocation each time an item is added to the container. In general, an *long* key has better performance than a *string* key.

## Time Complexity

The worst case and average case of the program is **O(NlogN)** where N is the number of input lines in the input file.

