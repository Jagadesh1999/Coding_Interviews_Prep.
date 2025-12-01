// Binary Search on answer :
// This means the search space is the answer itself.

// Atomic Item Contribution :
// 1. CSES - Factory Machines Problem.
// A factory has n machines which can be used to make products. Your goal is to make a total of t products.
// For each machine, you know the number of seconds it needs to make a single product. The machines can work simultaneously, and you can freely decide their schedule.
// What is the shortest time needed to make t products?

// Input : The first input line has two integers n and t: the number of machines and products.
//         The next line has n integers k_1,k_2,\dots,k_n: the time needed to make a product using each machine.

// Output : Print one integer: the minimum time needed to make t products.

// Input:
// 3 7
// 3 2 5

// Output:
// 8
// Explanation: By the end of 8 seconds, machine 1 makes two products, machine 2 makes four products and machine 3 makes one product.

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
} // TC : O(n * log(ans_range))

// Sweep-Technique Based Problems :
// 1. Painter Partition Problem.
// Can <= k painters finish the boards in mid seconds?
bool check(const vector<int>& nums, int mid, int k) {
    int paintersUsed = 0;
    int last_painter_time_left = 0;
    
    for(int i = 0; i < nums.size(); i++) {
        if(last_painter_time_left >= nums[mid]) {
            last_painter_time_left -= nums[i];
        } else {
            paintersUsed ++;
            last_painter_time_left = mid;
            
            if(last_painter_time_left >= nums[mid]) {
                last_painter_time_left -= nums[i];
            } else {
                return 0;
            }
        }
    }
    if(paintersUsed <= k) return 1;
    return 0;
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
} // TC : O(n * log(ans_range))


 

