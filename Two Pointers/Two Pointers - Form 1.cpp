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
// Head = -1; Tail = 0; Because we need the initial length to be zero.
// Think of a snake, it moves forward (head) and eats as many elements as it can.

// A. Template (TC : O(n))
// 1. For each position of tail, as long as it can contain atmost k 0s, keep incrementing the head unless you reach the end.
// 2. Calculate your answer for the range [Tail, Head].
// 3. For next iteration, move Tail one step ahead.

// B. Decide the Data structure.
// This is needed in order to quickly check if we can eat the next element or not.
// Here, a variable count should be enough for this problem.

// C. Decide the Answer :
// Here, max length is the ans. 
// So, ans = max(ans, Head - Tail + 1)

int solve(int[] nums, int k) {
    int head = -1; 
    int tail = 0;
    int count = 0; 
    int sol = 0;
    
    while(tail < nums.size() {
        // Step 1 : Keep eating as much as you can.
        while(head+1 < nums.size() && (nums[head+1] == 1 || count < k)) {
            head++;
            if(nums[head] == 0) count++;
        }

        // Step 2 : Update the answer
        sol = max(sol, head - tail + 1);

        // Step 3 : Move tail one step forward.
        if(tail <= head) {
            if(nums[tail] == 0) count--;
            tail++;
        } else {
            tail ++;
            head = tail - 1;
        }
    }
    return sol;
}

// 2. Find the number of subarrays with distinct elements <= k (atmost k distinct)
// Ask - count
// what needs to be found - subarrays
// monotonic criteria <= k

int solve(int[] nums, int k) {
    int head = -1; 
    int tail = 0;
    unordered_map<int, int> map; 
    int countDistinct = 0;
    int sol = 0;
    
    while(tail < nums.size() {
        // Step 1 : Keep eating as much as you can.
        while(head+1 < nums.size() && (map.count(nums[head + 1]) || countDistinct < k)) {
            head++; 
            
            // Increment frequency and check if it's a new distinct element
            map[nums[head]]++;
            if (map[nums[head]] == 1) { 
                countDistinct++;
            }
        }

        // Step 2 : Update the answer
        sol += (head - tail + 1); // Total number of subarrays.
        
        // Sum of length of all subarrays :
        // length = head - tail + 1;
        // sol += length * (length + 1) / 2;

        // Length of the longest subarray : 
        // sol = max(sol, head - tail + 1);

        // Step 3 : Move tail one step forward.
        if(tail <= head) {
            map[nums[tail]]--;
            if(map[nums[tail]] == 0) {
                countDistinct--;
            }
            tail++;
        } else {
            tail ++;
            head = tail - 1;
            map.clear(); 
            countDistinct = 0;
        }
    }
    return sol;
}

// TC : O(n), SC : O(distinct elements).

// 3. Total subarrays with exactly k distinct 
The solve function needs to return atmostKDistinct(nums, k) -  atmostKDistinct(nums, k - 1)

// 4. Total subarrays with atleast k distinct
The solve function needs to return (nums.size() * (nums.size() + 1) / 2) -  (atmostKDistinct(nums, k - 1))

Note : 
This subtraction trick works only for count versions.
For longest/shortest versions, be specific about conditions while updating the solution.



