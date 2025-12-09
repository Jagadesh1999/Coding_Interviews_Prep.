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
        // Pre Multiplication Check : To prevent LONG overflow.
        if (product > x / mid && i < n - 1) { 
             return 0; // Will definitely exceed x
        }
        
        // Actual Multiplication : 
        product *= mid;
        
        // Post Multiplication Check : Break early if product already exceeds x
        if (product > x && i < n - 1) {
            return 0;
        }
    }
    
    if (product <= x) return 1;
    else return 0;
}

// Atomic Item Contribution :
// CSES - Factory Machines Problem.
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

// 3. Koko eating Bananas.
bool check(vector<int>& piles, int mid, int h) {
    int total_hours = 0;
    for(int i = 0; i < piles.size(); i++) {
        total_hours += (piles[i] + mid - 1)/ mid;
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
    int low = 0;
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
} // TC : O(n * log(ans_range))

// 2. Largest Array Split Sum.
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
    int low = 0;
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
} // TC : O(n * log(ans_range))

// 3. Book Allocation Problem
// Can we allocate the books for <= k students in mid seconds?
bool check(const vector<int>& nums, int mid, int k) {
    int studentsUsed = 0;
    int last_student_time_left = 0;
    
    for(int i = 0; i < nums.size(); i++) {
        if(last_student_time_left >= nums[i]) {
            last_student_time_left -= nums[i];
        } else {
            studentsUsed ++;
            last_student_time_left = mid;
            
            if(last_student_time_left >= nums[i]) {
                last_student_time_left -= nums[i];
            } else {
                return 0;
            }
        }
    }
    if(studentsUsed <= k) return 1;
    return 0;
} 

int solve(const vector<int>& nums, int k) {
    int low = 0;
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
} // TC : O(n * log(ans_range))

// 4. Capacity to ship packages.
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
