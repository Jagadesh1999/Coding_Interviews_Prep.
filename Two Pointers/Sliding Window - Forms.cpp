// Two Pointers : 
// The framework that we will study is so powerful that it covers a vast variety of harder problems.

// Form 1 : Sliding Window Patterns - Fixed sized window
// Form 2 : Sliding Window Patterns - Dynamic sized window

// Discussion - Form 1 :
// ----------------------
// 1. Maximum Average Subarray Problem.
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left = 0; int right = 0;
        int currSum = 0; int maxSum = INT_MIN; 

        while(right < nums.size()) {
            // Step 1 : Allow always
            currSum += nums[right];
            
            // Step 2 : Can we remove..!?
            if(right >= k) {
                currSum -= nums[left];
                left++;
            }
            
            // Step 3 : Is it k-sized 
            if(right - left + 1 == k) {
                maxSum = max(maxSum, currSum);
            }
            right++;
        }
        return (double) maxSum / k;
    }
}; // TC : O(n)

// 2. Similar Variation : Maximum Sum Subarray Problem.

// 3. Sliding Window Maximum 

// You are given an array of integers nums, there is a sliding window of size k which is moving from the very left 
// of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves 
// right by one position. Return the max sliding window.

// Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
// Output: [3,3,5,5,6,7]

// Note : We will make use of the data structure Dequeue which has the property of FIFO.
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int left = 0; 
        int right = 0;
        
        deque<int> deque;
        vector<int> list;

        while(right < nums.size()) {
            while(!deque.empty() && (nums[deque.back()] < nums[right])) {
                deque.pop_back();
            }
            deque.push_back(right);

            if(right >= k) {
                if(!deque.empty() && deque.front() == left) {
                    deque.pop_front();
                }
                left++;
            }

            if(right - left + 1 == k) {
                list.push_back(nums[deque.front()]);
            }
            
            right++;
        }
        return list;
    }
};

// 4. First Negative Number of each subarray.
class Solution {
public:
    vector<int> solve(vector<int>& nums, int k) {
        int left = 0; 
        int right = 0;
        
        deque<int> deque;
        vector<int> list;

        while(right < nums.size()) {
            if(nums[right] < 0) {
                deque.push_back(right);
            }

            if(right >= k) {
                if(!deque.empty() && deque.front() == left) {
                    deque.pop_front();
                }
                left++;
            }

            if(right - left + 1 == k) {
                list.push_back(nums[deque.front()]);
            }
            
            right++;
        }
        return list;
    }
};

// 5. Count the occurences of the anagram in the string.
class Solution {
public:
    int search(string pat, string txt) {
        int k = pat.size();
        
        int left = 0, right = 0;
        int ans = 0;

        unordered_map<char, int> freq;
        for(char c : pat) freq[c]++; // Build frequency map of pattern
        int count = freq.size();  // distinct chars to be matched

        while(right < txt.size()) {
            // Step 1: Allow always
            if(freq.find(txt[right]) != freq.end()) {
                freq[txt[right]]--;
                if(freq[txt[right]] == 0)
                    count--;
            }

            // Step 2: Can we remove?
            if(right >= k) {
                if(freq.find(txt[left]) != freq.end()) {
                    freq[txt[left]]++;
                    if(freq[txt[left]] == 1)
                        count++;   
                }
                left++;
            }

            // Step 3: Is it k-sized?
            if(right - left + 1 == k) {
                if(count == 0)
                    ans++;
            }

            right++;
        }
        return ans;
    }
};

// Discussion - Form 2 :
// ---------------------
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
        while(head+1 < nums.size() && (count < k || (count == k && nums[head+1] == 1)) {
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
            count = 0; // Resetting the data structure.
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
    int sol = 0; // Be careful with this variable's initialization.
    
    while(tail < nums.size() {
        // Step 1 : Keep eating as much as you can.
        while(head+1 < nums.size() && (countDistinct < k  || (countDistinct == k && map[nums[head+1]] >= 1)) {
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
        // If Condition :
        // length = head - tail + 1;
        // sol += length * (length + 1) / 2;

        // Length of the longest subarray : 
        // sol = max(sol, head - tail + 1);

        // Step 3 : Move tail one step forward.
        if(tail <= head) {
            // Decrement the frequency before checking
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

// 5. Longest Substring without repeating characters.
int solve(string s) {
    int head = -1, tail = 0;
    unordered_map<char, int> freq;
    int sol = 0;
    
    while(tail < s.size()) {
        while(head+1 < s.size() && freq[s[head+1]] == 0) {
            head++;
            freq[s[head]]++;
        }
        sol = max(sol, head - tail + 1);
        
        if(tail <= head) {
            freq[s[tail]]--;
            tail++;
        } else {
            tail++; 
            head = tail - 1; 
            freq.clear(); // Resetting is most important.
        }
    }
    return sol;
}

// TC : O(n), SC : O(n)

// 6. Longest/Shortest substring with exactly k distinct
class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int head = -1;
        int tail = 0;
        unordered_map<char, int> freq;
        int countDistinct = 0;
        int sol = -1;
        
        while(tail < s.size()) {
            while(head + 1 < s.size() && ((countDistinct < k) || (countDistinct == k && freq[s[head+1]] >= 1 ))) {
                head++;
                freq[s[head]]++;
                if(freq[s[head]] == 1) countDistinct++;
            }
            
            if(countDistinct == k) sol = max(sol, head - tail + 1);
            
            if(tail <= head) {
                freq[s[tail]]--;
                if(freq[s[tail]] == 0) countDistinct--;
                tail++;
            } else {
                tail ++;
                head = tail - 1;
                countDistinct = 0;
                freq.clear();
            }
        }
        return sol;
    }
};

// Think about the problems :
// Longest/Shortest substring with atmost k distinct
// Longest/Shortest substring with atleasr k distinct

// 7. Fruits into Baskets. - Length of the longest subarray with atmost k distinct elements.

// 8. Longest Repeating Character Replacement.
// Key Insight: In any window, changes_needed = window_length - max_frequency_of_any_char
// Note : Use frequency map and max_freq combination as the data structure.

class Solution {
public:
    int characterReplacement(string s, int k) {
        int head = -1, tail = 0;
        unordered_map<char, int> freq;
        int maxFreq = 0;
        int sol = 0;
        
        while(tail < s.size()) {
            // Template: CHECK BEFORE adding (predict next window)
            while(head+1 < s.size() && 
                  // Predict: if we add s[head+1], will it be valid?
                  (head+1 - tail + 1 - max(maxFreq, freq[s[head+1]] + 1) <= k)) {
                head++;
                freq[s[head]]++;
                maxFreq = max(maxFreq, freq[s[head]]);
            }
            
            sol = max(sol, head - tail + 1);
            
            if(tail <= head) {
                freq[s[tail]]--;
                maxFreq = 0;
                for(auto& p : freq) if(p.second > 0) maxFreq = max(maxFreq, p.second); // Most important
                tail++;
            } else {
                tail++; 
                head = tail-1; 
                freq.clear(); 
                maxFreq = 0;
            }
        }
        return sol;
    }
};

// TC : O(n), SC : O(26) = O(1)

// 9. Given an array containing N positive integers and an integer K. Your task is to find the length of the longest 
// Sub-Array with sum of the elements equal to the given value K.
    
int longestSubarrayWithSumK(vector<int>& nums, int K) {
    int head = -1, tail = 0;
    int currSum = 0;
    int sol = 0;

    while(tail < n) {
        // Step 1: Eat as much as you can
        while(head + 1 < nums.size() && currSum + nums[head + 1] <= K) {
            head++;
            currSum += nums[head];
        }

        // Step 2: Update answer
        if(currSum == K) {
            sol = max(sol, head - tail + 1);
        }

        // Step 3: Move tail
        if(tail <= head) {
            currSum -= nums[tail];
            tail++;
        } else {
            tail++;
            head = tail - 1;
            currSum = 0;
        }
    }
    return sol;
} // TC : O(n), SC : O(1)

// 10. Minimum Window Substring.
// Given two strings s and t, return the minimum window in s which will contain all the characters in t. If there is 
// no such window in s that covers all characters in t, return the empty string "".
// Note that If there is such a window, it is guaranteed that there will always be only one unique minimum window in s.

// Example 1:

// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> freq;
        for(char c : t) freq[c]++;

        int count = freq.size();
        int head = -1, tail = 0;
        int minLen = INT_MAX;
        int start = 0;

        while(tail < s.size()) {
            // Step 1: Eat until window becomes valid
            while(head + 1 < s.size() && count > 0) {
                head++;
                if(freq.find(s[head]) != freq.end()) {
                    freq[s[head]]--;
                    if(freq[s[head]] == 0)
                        count--;
                }
            }

            // Step 2: Update answer (window is valid)
            if(count == 0 && head - tail + 1 < minLen) {
                minLen = head - tail + 1;
                start = tail;
            }

            // Step 3: Move tail
            if(tail <= head) {
                if(freq.find(s[tail]) != freq.end()) {
                    if(freq[s[tail]] == 0)
                        count++;
                    freq[s[tail]]++;
                }
                tail++;
            } else {
                tail++;
                head = tail - 1;
                freq.clear();
                for(char c : t) freq[c]++;
                count = freq.size();
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};


