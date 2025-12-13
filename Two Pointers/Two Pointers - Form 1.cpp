// Two Pointers : 
// The framework that we will study is so powerful that it covers a vast variety of harder problems.

// Form 0 : Fixed sized window - Sliding Window Patterns
// Form 1 : 2 pointers moving in same direction (same array)
// Form 2 : 2 pointers moving in opposite direction (same array)
// Form 3 : 2 pointers moving in same direction (different array)

// 1. Find the longest subarray of all 1s with atmost k flips. 

// Longest - ask (It could be longest, shortest, count, sum of length).
// Subarray - what needs to be found (It could be subarray, max - min (gap)).
// atmost k flips - criteria (It could be any monotonic criteria) 
// Criteria - No. of 0s in (L -> R) <= k
//          - Also true for (L+1 -> R) <= k
//          - Criteria proved monotonic.

// Brute Force is O(n ^ 2).

// [0, 1, 0, 1, 0, 0, 1, 1, 0] 
// Head = -1; Tail = 0;
// Think of a snake, it moves forward (head) and eats as many elements as it can.

// Template (TC : O(n))
// 1. For each position of tail, as long as it can contain atmost k 0s, keep incrementing the head unless you reach the end.
// 2. Calculate your answer for the range [Tail, Head].
// 3. For next iteration, move Tail one step ahead.

 
