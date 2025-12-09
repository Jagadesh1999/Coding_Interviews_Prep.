// Binary Search on answer :
// This means the search space is the answer itself.

// 1. Square root of a number.
// Note : This problem needs to be transformed in such a way that it needs to be 1 1 1 . . . 1 0 0 . . . 0 0 
// Finding the index of the last occurence of 1 is the answer

bool check(int mid, int x) {
    if((long) mid * mid <= x) return 1; // sol = mid; low = mid + 1
    else return 0; // high = mid - 1.
} // TC : O(log n)

// 2. Nth root of a number using binary search.
bool check(int mid, int x, int n) {
    if (mid == 0) return 1; // Special case for mid=0, as 0^n = 0 <= x (for non-negative x)

    long product = 1;
    for (int i = 0; i < n; i++) {
        if (product > x / mid && i < n - 1) { // Pre Multiplication Check : To prevent LONG overflow.
             return 0; 
        }
         
        product *= mid; // Actual Multiplication

        if (product > x && i < n - 1) { // Post Multiplication check : To check if the product exceeded.
            return 0;
        }
    }
    
    if (product <= x) return 1;
    else return 0;
}

// Atomic Item Contribution :
// 1. CSES - Factory Machines Problem.
// A factory has n machines which can be used to make products. Your goal is to make a total of t products.
// For each machine, you know the number of seconds it needs to make a single product. The machines can work simultaneously, and you can freely decide their schedule.
// What is the shortest time needed to make t products?

// Tip : We do get the essence of "How much is enough?" in the question. Thats a good indication that is a BS Problem.

// Observations :
// -- The time will be the search space in this problem.
// -- We will create a check(t), that tells, is t seconds enough?
// -- In the above problem, everything from 8 seconds is enough. So, they will be the sequence of 1s.
// -- Everything before that will be the sequence of 0s. 
// -- Hence, we have reframed the problem statement in such a way that finding the first 1 is the ans.

// low = 0; 
// high = any k value * t (because that machine will be able produce t products)
//        but preferred is min k value because this makes the search space smaller.
//        If you want to play safe without any confusion, do arr[i] * t

// Products each machine makes in 'mid' seconds is mid / time[i]

// Can we make t products in mid seconds?
bool check(const vector<int>& nums, int mid, int total_products) {
    int numberOfProductsMade = 0;
    for(int i = 0; i < nums.size(); i++) {
        numberOfProductsMade += mid / nums[i];
        if(numberOfProductsMade >= total_products) return 1;
    }
    return 0;
} 

int solve(const vector<int>& nums, int total_products) {
    int low = 1;
    int high = nums[i] * total_products;
    int sol = -1;

    while(low <= high) {
        int mid = low + (high - low) / 2;
        
        if(check(nums, mid, k)) {
            sol = mid;
            high = mid - 1;
        }else {
            low = mid + 1;
        }
    }
    return sol;   
}// TC : O(n * log(ans_range))

// 2. Koko eating Bananas.
// Problem Statement: A monkey Koko is given ‘n’ piles of bananas, whereas the 'ith' pile has ‘a[i]’ bananas. 
// An integer ‘h’ is also given, which denotes the time (in hours) for all the bananas to be eaten.
// Each hour, the monkey chooses a non-empty pile of bananas and eats ‘k’ bananas. If the pile contains less than ‘k’ bananas, then the monkey consumes all the bananas and won’t eat any more bananas in that hour.
// Find the minimum number of bananas ‘k’ to eat per hour so that the monkey can eat all the bananas within ‘h’ hours.
bool check(vector<int>& piles, int mid, int h) {
    int total_hours = 0;
    for(int i = 0; i < piles.size(); i++) {
        total_hours += (piles[i] + mid - 1)/ mid; // To calculate the ceil perfectly.
        if(total_hours > h) return 0;
    }
    return 1;
} 

int solve(const vector<int>& nums, int total_products) {
    int low = 1;
    int high = *max_element(nums.begin(), nums.end());
    int sol = -1;

    while(low <= high) {
        int mid = low + (high - low) / 2;
        
        if(check(nums, mid, k)) {
            sol = mid;
            high = mid - 1;
        }else {
            low = mid + 1;
        }
    }
    return sol;   
}// TC : O(n * log(ans_range))

// Sweep-Technique Based Problems :
// 1. Painter Partition Problem.
// Problem Statement: 
// Given an array/list of length ‘N’, where the array/list represents the boards and each element of 
// the given array/list represents the length of each board. Some ‘K’ numbers of painters are available to paint these 
// boards. 
// Consider that each unit of a board takes 1 unit of time to paint. 
// You are supposed to return the area of the minimum time to get this job done of painting all the ‘N’ boards under the constraint that any painter will only paint the continuous sections of boards.

// Can <= k painters finish the boards in mid seconds?
bool check(const vector<int>& nums, int mid, int k) {
    int paintersUsed = 0;
    int last_painter_time_left = 0;
    
    for(int i = 0; i < nums.size(); i++) {
        if(last_painter_time_left >= nums[i]) {
            last_painter_time_left -= nums[i];
        } else {
            paintersUsed ++;
            last_painter_time_left = mid;
            
            if(last_painter_time_left >= nums[i]) {
                last_painter_time_left -= nums[i];
            } else {
                return 0;
            }
        }
    }
    if(paintersUsed <= k) return 1;
    return 0;
} 

int solve(const vector<int>& nums, int k) {
    int low = *max_element(nums.begin(), nums.end());;
    int high = accumulate(nums.begin(), nums.end(), 0);
    int sol = -1;

    while(low <= high) {
        int mid = low + (high - low) / 2;
        
        if(check(nums, mid, k)) {
            sol = mid;
            high = mid - 1;
        }else {
            low = mid + 1;
        }
    }
    return sol;   
} // TC : O(n * log(ans_range))

// 2. Largest Array Split Sum.
// Problem Statement: 
// Given an integer array ‘A’ of size ‘N’ and an integer ‘K'. Split the array ‘A’ into ‘K’ non-empty subarrays such 
// that the largest sum of any subarray is minimized. Your task is to return the minimized largest sum of the split. 
// A subarray is a contiguous part of the array.

// Can we split the array into <= k subarrays such that each subarray has sum <= mid?
bool check(const vector<int>& nums, int mid, int k) {
    int splitsMade = 0;
    int last_split_space_left = 0;
    
    for(int i = 0; i < nums.size(); i++) {
        if(last_split_space_left >= nums[i]) {
            last_split_space_left -= nums[i];
        } else {
            splitsMade ++;
            last_split_space_left = mid;
            
            if(last_split_space_left >= nums[i]) {
                last_split_space_left -= nums[i];
            } else {
                return 0;
            }
        }
    }
    if(splitsMade <= k) return 1;
    return 0;
} 

int solve(const vector<int>& nums, int k) {
    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);
    int sol = -1;

    while(low <= high) {
        int mid = low + (high - low) / 2;
        
        if(check(nums, mid, k)) {
            sol = mid;
            high = mid - 1;
        }else {
            low = mid + 1;
        }
    }
    return sol;   
} // TC : O(n * log(ans_range))

// 3. Book Allocation Problem
// Problem Statement: 
// Given an array ‘arr of integer numbers, ‘ar[i]’ represents the number of pages in the ‘i-th’ book. There are a ‘m’ number of students, and the task is to allocate all the books to the students.
// Allocate books in such a way that:

// Each student gets at least one book.
// Each book should be allocated to only one student.
// Book allocation should be in a contiguous manner.
// You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum. If the allocation of books is not possible. return -1

// Can we allocate the books for <= k students in mid seconds?
bool check(const vector<int>& nums, int mid, int k) {
    int studentsUsed = 0;
    int last_student_pages_left = 0;
    
    for(int i = 0; i < nums.size(); i++) {
        if(last_student_pages_left >= nums[i]) {
            last_student_pages_left -= nums[i];
        } else {
            studentsUsed ++;
            last_student_time_left = mid;
            
            if(last_student_pages_left >= nums[i]) {
                last_student_pages_left -= nums[i];
            } else {
                return 0;
            }
        }
    }
    if(studentsUsed <= k) return 1;
    return 0;
} 

int solve(const vector<int>& nums, int k) {
    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);
    int sol = -1;

    while(low <= high) {
        int mid = low + (high - low) / 2;
        
        if(check(nums, mid, k)) {
            sol = mid;
            high = mid - 1;
        }else {
            low = mid + 1;
        }
    }
    return sol;   
} // TC : O(n * log(ans_range))

// 4. Capacity to ship packages.
// Problem Statement: 
// You are the owner of a Shipment company. You use conveyor belts to ship packages from one port to another. 
// The packages must be shipped within 'd' days. The weights of the packages are given in an array 'of weights'. 
// The packages are loaded on the conveyor belts every day in the same order as they appear in the array. 
// The loaded weights must not exceed the maximum weight capacity of the ship. 
// Find out the least-weight capacity so that you can ship all the packages within 'd' days.

// For a given trial capacity, mid, we are trying to find out if mid is the maximum weight capacity the ship can 
// handle on any single day. We then calculate the minimum number of days needed in order to ship all the packages, 
// and return true (1) if the required days are less than or equal to the constraint $D$, or false (0) otherwise.

class Solution {
public:
    bool check(vector<int>& weights, int mid, int days) {
        int daysUsed = 0;
        int current_capacity_left = 0;

        for(int i = 0; i < weights.size(); i++) {
            if(current_capacity_left >= weights[i]) {
                current_capacity_left -= weights[i];
            } else {
                daysUsed ++;
                current_capacity_left = mid;
                
                if(current_capacity_left >= weights[i]) {
                    current_capacity_left -= weights[i];
                } else {
                    return 0;
                }
            }
        }
        if(daysUsed <= days) return 1;
        return 0;
    }

    int solve(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int sol = -1;

        while(low <= high) {
            int mid = low + (high- low) / 2;
            if(check(weights, mid, days)) {
                sol = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return sol;    
    }
}; // TC : O(n * log(ans))

// 5. Aggressive Cows Problem.
// Problem Statement: 
// You are given an array 'arr' of size 'n' which denotes the position of stalls. You are also given an integer 'k' which denotes the number of aggressive cows.
// You are given the task of assigning stalls to 'k' cows such that the minimum distance between any two of them is the maximum possible. Find the maximum possible minimum distance.

#include <vector>
#include <algorithm>
#include <cmath>

bool check(const std::vector<int>& stalls, int mid, int k) {
    int cowsPlaced = 0; 
    long long lastCowPosition = -2000000000LL; // Use long long for a safely small number
    
    for (int i = 0; i < stalls.size(); i++) {
        
        if (stalls[i] - lastCowPosition >= mid) {
            
            cowsPlaced++;
            lastCowPosition = stalls[i];
            
            if (cowsPlaced >= k) {
                return 1;
            }
        }
    }
    return 0;
}

int solve(std::vector<int>& stalls, int k) {
    std::sort(stalls.begin(), stalls.end());

    int n = stalls.size();
    int low = 1; 
    int high = stalls[n - 1] - stalls[0]; 
    int sol = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (check(stalls, mid, k)) {
            sol = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return sol;
}
