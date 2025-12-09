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
// Always try to convert any binary search problem into this foundational problem using the check(mid) function.
// The check(mid) function needs to constructed in such a manner that it returns 0 for onse set of values and 
   // for the next set of values, it needs to return 1. Then, finding the occurence of the first one is the solution.


// Discussion of Applications : (Only the check(mid) function needs to be changed!)
// --------------------------------------------------------------------------------
// 1. Lower-Bound 
// S. Inside the check(mid) function --> if (nums[mid] >= x), return 1

// 2. Upper-Bound 
// S. Inside the check(mid) function --> if (nums[mid] > x), return 1

// 3. Search Insert Position
// Samples :
   // Input: nums = [1, 3, 5, 6], target = 5. Output: 2. Explanation: The target value 5 is found at index 2 in the sorted array. Hence, the function returns 2.
   // Input: nums = [1, 3, 5, 6], target = 2. Output: 1. Explanation: The target value 2 is not found in the array. However, it should be inserted at index 1 to maintain the sorted order of the array.
// S. Inside the check(mid) function :
      // --> if (nums[mid] >= x), return 1
      // --> if it returns 1, then inside the while loop, check if (nums[mid] == x), if yes, sol = mid; break;
      // -->                                                                         if no, sol = mid; high = mid - 1

// 4. Floor and ceil of the target in the sorted array.
// S. Inside the check(mid) function : if(nums[mid] >= target), return 1
      // --> sol will store the ceil value at the exit of the while loop.
      // --> If ceil == target, then floor is also the same value as ceil, else floor is the value of the element previous to that of the floor.

// 5. Last occurence of the given target in the sorted array. (Consider a small change we are finding the index of the last 0, instead of the first one)
// S. Inside the check(mid) function : if(nums[mid] == x), return 0.
      // Inside the loop, If check(mid) == 0, sol = mid; low = mid + 1
      // Else, check if(nums[mid] > target), YES - high = mid - 1. NO - low = mid + 1.

// 6. Count the occurences of a given number in the sorted array.
// S. The problem needs to be solved using 2 parts, the first occurence part and the last occurence part. (L - F + 1) is the total occurence.

// 7. Search in rotated sorted array (Distinct elements Version)
// Tips : In the rotated sorted array with distinct elements, for any element mid, one half is sorted and the other half is not sorted.
// S. First check if nums(mid) is the target and return accordingly.
      // Inside the check(mid) function :
         // 1. Check if left half is sorted (nums[low] <= nums[mid]) and if yes, search for the target in that half (nums[low] <= target < nums[mid]).
               // If the element lies in that range, do high = mid - 1, Else do low = mid + 1.
         // 2. Else if the left half is not sorted, search for the target in the right half (nums[mid] <= target < nums[high]). 
               // If the element lies in that range, do low = mid + 1. else do high = mid - 1.

// 8. Search in rotated sorted array (Duplicates elements Version)
// S. First check if nums(mid) is the target and return accordingly.
      // Inside the check(mid) function :
         // 1. Check if left half is sorted (nums[low] < nums[mid]) and if yes, search for the target in that half (nums[low] <= target < nums[mid]).
               // If the element lies in that range, do high = mid - 1, Else do low = mid + 1.
         // 2. Else if the left half is not sorted, search for the target in the right half (nums[mid] <= target < nums[high]). 
               // If the element lies in that range, do low = mid + 1. else do high = mid - 1.
         // 3. Else, shrink at both the ends. do low++ and high--.

// 9. Minimum in Rotated Sorted Array (The elements are distinct and the rotations are anti-clockwise)
// S. Inside the check(mid) function --> if (nums[mid] <= nums[nums.size()-1]), return 1 
   // Think why the comparison with nums[0] might disturb the monotonic property when the input array is perfectly sorted.
   // Similar Problem - Find out the total number of rotations in the rotated sorted array.
   // The simple observation and the code change needed if the rotations were clockwise.
      // Still, the minimum element stays the same.
      // No further code change is needed. 
      // The only formula needed is, Rotations = nums.size() - nums[sol].
// Note : Try to understand the solution approach for the duplicates version before the interviews.

// 10. Every element occurs twice except the single element. Find that single Element in a Sorted Array.
// Tips: The core idea is that the single element breaks the pattern:
//       Before the single element, pairs are (Even Index, Odd Index).
//       After the single element, pairs are (Odd Index, Even Index).

// We search for the first index 'mid' where the pattern is broken.
int findSingleElement(const vector<int>& nums) {
    int low = 0;
    // The single element will always be the last element if the low <= high loop finishes without finding it.
    // The search space is up to the second-to-last element to safely check mid+1.
    int high = nums.size() - 1; 
    int sol = nums.size();
    
    while(low <= high) {
        int mid = low + (high - low) / 2;
        
        // 1. Ensure 'mid' is at an even index for consistent pattern checking.
        //    If 'mid' is odd, move it back to the preceding even index.
        //    Example: if mid=3, mid & 1 is true. mid-- makes it mid=2.
        //    This simplifies the logic to always check (mid, mid+1) where 'mid' is even.
        if (mid % 2 != 0) { 
            mid--;
        }
        
        // 2. Check the pattern: If nums[mid] == nums[mid+1], it means 'mid' is part of a pair
        //    that is BEFORE the single element (correct pattern: Even, Odd).
        //    The single element must be in the right half.
        if (mid != nums.size()-1 && nums[mid] == nums[mid + 1]) {
            low = mid + 2; // Move low past this pair (mid and mid+1)
        } 
        // 3. Else, the single element must be either nums[mid] itself or in the left half.
        //    The pattern is broken: nums[mid] != nums[mid+1].
        //    Store potential answer and search the left half.
        else {
            // nums[mid] could be the single element (or the start of the reversed pattern)
            sol = mid;
            high = mid - 1; 
        }
    }
    
    // The loop terminates when low > high, and 'low' points to the first element
    // of a pair that is *not* equal to its neighbour, meaning it's the single element.
    return sol;
}

/*
int main() {
    // Input: [1, 1, 2, 3, 3, 4, 4, 8, 8] -> Output: 2
    vector<int> nums1 = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << "The single element is: " << findSingleElement(nums1) << endl; 
    
    // Input: [3, 3, 7, 7, 10, 11, 11] -> Output: 10
    vector<int> nums2 = {3, 3, 7, 7, 10, 11, 11};
    cout << "The single element is: " << findSingleElement(nums2) << endl; 

    // Input: [1, 2, 2] -> Output: 1
    vector<int> nums3 = {1, 2, 2};
    cout << "The single element is: " << findSingleElement(nums3) << endl; 
    
    return 0;
}
*/
      
// 11. Index of the peak element in a bitonic array - (Bitonic array - value increases strictly till one point and then it starts strictly decreasing)
// S. Inside the check(mid) function --> if ((mid < nums.size()-1) && (nums[mid] > nums[mid+1]), return 1
                                //   --> if (mid == nums.size()-1) return 1 
                                //   --> return 0.
      
                                
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
                                
                                
                                
