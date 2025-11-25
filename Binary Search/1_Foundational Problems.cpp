// Binary Search : 
// -- Efficient searching algorithm used in a sorted data that works in O(log n) time complexity.
// -- Even in unsorted data structure, if there is a monotonic function, we can use the binary search algorithm.


#include <bits/stdc++.h>
using namespace std;

bool solve() {
   int size; 
   cin >> size;
   
   vector<int> nums(size);
   for(int i = 0; i < size; i++) {
       cin >> nums[i];
   }
   
//   int nums[size];
//   for(int i = 0; i < size; i++) {
//       cin >> nums[i];
//   }
   
   
   int target;
   cin >> target;
   
   int low = 0; 
   int high = nums.size() - 1; // int high = size - 1;
   
   while(low <= high) {
       int mid = low + (high - low) / 2;
       
       if(nums[mid] == target) {
           return true;
       } else if(nums[mid] < target) {
           low = mid + 1;
       } else {
           high = mid - 1;
       }
   }
   
   return false;
}

int main()
{
    bool isTargetPresent = solve();
    if(isTargetPresent) cout << "The target is found in the array";
    else cout << "The target is not present";
    
    return 0;
}

// Binary Search - Foundational Problem
// Index of the first 1 in a binary sorted array containing 0s and 1s.

// (Use 4 variables to solve these kind of binary search problems)
// (Build check function instead of check array to retain the log n complexity)

// Similar Problems :
// 1. Array - [1,1,1,1,0,0,0,0] - Return the index of the first 0.
// 2. Array - [1,1,1,1,0,0,0,0] - Return the index of the last 1. 
        // 1st Approach - Index of first 0 - 1.
        // 2nd Approach - Change the structure to find the index of the rightmost 1.

#include <bits/stdc++.h>
using namespace std;

bool check(int mid, const vector<int>& nums) {
    if(nums[mid] == 1) return 1;
    return 0;
}

void solve(const vector<int>& nums) {
    int low = 0; 
    int high = nums.size() - 1;
    int sol = -1;
    
    while(low <= high) {
        int mid = low + (high - low) / 2;
        
        if(check(mid, nums)) {
            sol = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << sol << "\n";
}

int main()
{
    int size;
    cin >> size;
    
    vector<int> nums(size);
    for(int i = 0; i < size; i++) {
        cin >> nums[i];
    }
    
    solve(nums);
    return 0;
}


// Discussion of Applications : (Only the check(mid) function needs to be changed!)
// --------------------------------------------------------------------------------
// 1. Lower-Bound 
// S. Inside the check(mid) function --> if (nums[mid] >= x), return 1

// 2. Upper-Bound 
// S. Inside the check(mid) function --> if (nums[mid] > x), return 1

// 3. Minimum in Rotated Sorted Array (The elements are distinct and the rotations are anti-clockwise)
// S. Inside the check(mid) function --> if (nums[mid] <= nums[nums.size()-1]), return 1 
   // Think why the comparison with nums[0] might disturb the monotonic property when the input array is perfectly sorted.
   // Similar Problem - Find out the total number of rotations in the rotated sorted array.
   // The simple observation and the code change needed if the rotations were clockwise.
      // Still, the minimum element stays the same.
      // No further code change is needed. 
      // The only formula needed is, Rotations = nums.size() - nums[sol].
      
// 4. Index of the peak element in a bitonic array - (Bitonic array - value increases strictly till one point and then it starts strictly decreasing)
// S. Inside the check(mid) function --> if ((mid < nums.size()-1) && (nums[mid] > nums[mid+1]), return 1
                                //   --> if (mid == nums.size()-1) return 1 
                                //   --> return 0.
                                
                                
// Common ideas for check(mid) function :
// --------------------------------------
// 1. Element to be compared with the external element. Ex : Lower-Bound
// 2. Element to be compared with the first/last element. Ex : Minimum in ROtated Sorted Array
// 3. Element to be compared with the prev/next element. Ex : Peak in Bitonic array                                
                                
// Some unique problems that does not follow monotonicity and technically not a BS problem but needs a binary search like logic :
// ------------------------------------------------------------------------------------------------------------------------------
// 1. Find any one peak element 
// S. 3 possible condition checks inside check(mid) function. 
   // Edge case : Left boundary
   // if (mid == 0) {
   //     return n > 1 && nums[mid] > nums[mid + 1];
   // }
   
   // Edge case : Right boundary
   // if (mid == n - 1) {
   //     return n > 1 && nums[mid] > nums[mid - 1];
   // }
   
   // General case :
   // return nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1];
   
   // This is more of a maths or an observation based problem as binary search cannot be used to find any peak.
   // BS is used to find one exact answer.
                                
                                
                                

