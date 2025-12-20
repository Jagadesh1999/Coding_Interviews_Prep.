// Two Pointers : 
// --------------
// Form 1 : 2 pointers moving in opposite direction (same array)
// Form 2 : 2 pointers moving in same direction (different array)

// Discussion - Form 1 :
// ---------------------
// 1. Two Sum Problem for the sorted array.
// Input : nums = [10, 20, 30, 40, 50], target = 70.
// Output : 1 // 20 + 50 = 70

// Brute Force Approach : 
// -- For each element, try adding that particular element with the other elements of the array one by one and calculate the sum.
// -- If there exists any pair whose sum is equal to the target, then return true. 
// -- If there exists no such combination, then return false.
// -- TC : O(n^2), SC : O(1)

// Better Approach : 
// -- Have two pointers, one at the start and one at the end.
// -- while (left < right) : 
  // -- Compare the nums[start] + nums[end] with the target.
  // -- Since the array is sorted, based on the sum, either increment the start if the sum needs to be increased or decrement the end if the sum needs to be decreased.
// TC : O(n), SC : O(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0; 
        int right = nums.size()-1;
        vector<int> result;

        while(left < right) {
            if(nums[left] + nums[right] == target) {
                result.push_back(left+1); // We need to return 1-based indices
                result.push_back(right+1);
                return result;
            } else if(nums[left] + nums[right] < target) {
                left ++;
            } else {
                right --;
            }
        }
        return {};
    }
};

// If the same problem statement is tweaked to return the list of all the pairs whose sum equals k, then the code is,
// Input - Distinct elements version.
class Solution {
public:
    vector<vector<int>> twoSum(vector<int>& nums, int target) {
        int left = 0; 
        int right = nums.size() - 1;
        vector<vector<int>> allResults; // Changed to store multiple pairs
        // int count = 0;

        while (left < right) {
            if (nums[left] + nums[right] == target) {
                allResults.push_back({left + 1, right + 1});
                // count ++;
                left++;
                right--;
            } else if (nums[left] + nums[right] < target) {
                left++;
            } else {
                right--;
            }
        }
        return allResults;
        // return count;
    }
};

// Input - Duplicates elements version.
class Solution {
public:
    vector<vector<int>> twoSum(vector<int>& nums, int target) {
        int left = 0; 
        int right = nums.size() - 1;
        vector<vector<int>> allResults; // Changed to store multiple pairs

        while (left < right) {
            if (nums[left] + nums[right] == target) {
                allResults.push_back({left + 1, right + 1});
              
                while (left < right && nums[left] == nums[left + 1]) left++; // Skip all the identical elements
                while (left < right && nums[right] == nums[right - 1]) right--; // Skip all the identical elements.

                left ++;
                right --;     
            } else if (nums[left] + nums[right] < target) {
                left++;
            } else {
                right--;
            }
        }
        return allResults;
    }
};

// If the problem statement is to find the total number of pairs in the sorted array (Duplicates version)
int countPairsDuplicates(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    int totalCount = 0;

    while (left < right) {
        if (nums[left] + nums[right] == target) {
            // Check if the elements are the same
            if (nums[left] == nums[right]) {
                int n = right - left + 1;
                totalCount += (n * (n - 1)) / 2; // Combination formula: nC2
                break; // All pairs between left and right are now counted
            } else {
                // Count occurrences of nums[left]
                int leftVal = nums[left], countLeft = 0;
                while (left < right && nums[left] == leftVal) {
                    countLeft++;
                    left++;
                }
                // Count occurrences of nums[right]
                int rightVal = nums[right], countRight = 0;
                while (right >= left && nums[right] == rightVal) {
                    countRight++;
                    right--;
                }
                totalCount += (countLeft * countRight);
            }
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    return totalCount;
}

// 2. Container with most water
// f(i, j) - min(arr[i], arr[j]) * j - 1;
// Brute Force - Check for all the possible pairs of lines - O(n^2)
// Optimised Approach - Two Pointers
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;

        while(left < right) {
            int currArea = min(height[left], height[right]) * (right - left);
            maxArea = max(currArea, maxArea);

            if(height[left] == height[right]) {
                // Shrink at both the edges to get rid of the duplicates
                left++; 
                right--;
            }
            else if(height[left] < height[right]) {
                left++; // Know the proof behind this conclusion
            } else {
                right--; // Know the proof behind this conclusion
            }
        }
        return maxArea;
    }
};

// 3. 3 Sum Problem - Count the number of triplets.
Brute Force Approach : O(n^3).
  
Optimised Approach : 
Step 1 : 
Sort the array - O(n log n)

Step 2 : 
i iterates from 0 to nums.size()-3.
For each iteration of i, have two pointers left(i+1) and right(nums.size()-1)

Step 3 : 
Run the inner while loop (left < right) 
Calculate the sum, if (nums[i] + nums[left] + nums[right] == target) {
  count++; 
  left++;
  right--;
}
Else if (nums[i] + nums[left] + nums[right] < target) left++;
Else right--;

Return the count at the last.

// Critical ideas to think :
// Tackle the same problem when we are asked to check if we have the valid target.
// Tackle the same problem when we are asked to return one triplet whose sum equals target.

// Discussion - Form 2 : 
// ---------------------
// 1. Is Subsequence?
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int j = 0;

        while(i < s.length() && j < t.length()) {
            if(s[i] == t[j]) { // Found the match, so move both the pointers.
                i++; 
                j++;
            } else {
                j++;
            }
        }

        if(i == s.length()) return 1;
        return 0;
    }
}; 

// 2. Intersection of 2 sets in the sorted array.
// [2, 3, 4, 5]  
// [1, 2, 5]

// Approach : 
// Match, take the element in the sol set and move both the pointers ahead.
// If no match, move the pointer of the smallest element ahead.

// 2. Union of 2 sets in the sorted array
// [2, 3, 4, 5]  
// [1, 2, 5]

// Approach : 
// Match, take the element in the sol set and move both the pointers ahead.
// If no match, take the smallest element in the set and move the pointer of the smallest element ahead.
