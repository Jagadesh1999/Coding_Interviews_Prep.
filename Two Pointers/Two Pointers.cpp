// Two Pointers : 
// --------------
// Form 1 : 2 pointers moving in opposite direction (same array)
// Form 2 : 2 pointers moving in same direction (different array)

// 1. Container with most water
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

// 2. 3 sum (Distinct input)
// 2.1 - Return boolean if a valid triplet exists
bool hasTriplet(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < n - 2; i++) {
        int left = i + 1, right = n - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == target) return true;
            else if (sum < target) left++;
            else right--;
        }
    }
    return false;
}

// 3.2 - Return any one triplet
vector<int> getOneTriplet(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < n - 2; i++) {
        int left = i + 1, right = n - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == target) return {nums[i], nums[left], nums[right]};
            else if (sum < target) left++;
            else right--;
        }
    }
    return {};
}

// 3.3 - Return all triplets
// Note: Since elements are distinct, "All Triplets" and "All Unique Triplets" are effectively the same problem.
vector<vector<int>> getAllTriplets(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    int n = nums.size();
    for (int i = 0; i < n - 2; i++) {
        int left = i + 1, right = n - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == target) {
                res.push_back({nums[i], nums[left], nums[right]});
                left++; 
                right--;
            } 
            else if (sum < target) left++;
            else right--;
        }
    }
    return res;
}

// 3.4 - Count all triplets
// Note: Because every element is unique, we don't need to count inner frequencies; every match found is a single unique triplet.
int countAllTriplets(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int totalCount = 0;
    int n = nums.size();
    for (int i = 0; i < n - 2; i++) {
        int left = i + 1, right = n - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == target) {
                totalCount++;
                left++;
                right--;
            } 
            else if (sum < target) left++;
            else right--;
        }
    }
    return totalCount;
}

// 3. 3 Sum Problem (Duplicates)
// 3.1 - Return the boolean if the valid triplet exists or not.
bool hasTriplet(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    for (int i = 0; i < (int)nums.size() - 2; i++) {
        int left = i + 1, right = nums.size() - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == target) return true;
            else if (sum < target) left++;
            else right--;
        }
    }
    return false;
}

// 3.2 - Return any one triplet
vector<int> getOneTriplet(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    for (int i = 0; i < (int)nums.size() - 2; i++) {
        int left = i + 1, right = nums.size() - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == target) return {nums[i], nums[left], nums[right]};
            else if (sum < target) left++;
            else right--;
        }
    }
    return {};
}

// 3.3 - Return all the triplets.
vector<vector<int>> getAllTriplets(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end()); // Sorting helps, but won't prevent duplicates here
    vector<vector<int>> res;
    for (int i = 0; i < (int)nums.size() - 2; i++) {
        int left = i + 1, right = nums.size() - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == target) {
                res.push_back({nums[i], nums[left], nums[right]});
                // To get ALL combinations of these values, we must explore further
                // without skipping identical values.
                int tempRight = right - 1;
                while (tempRight > left && nums[i] + nums[left] + nums[tempRight] == target) {
                    res.push_back({nums[i], nums[left], nums[tempRight]});
                    tempRight--;
                }
                left++;
            } 
            else if (sum < target) left++;
            else right--;
        }
    }
    return res;
}

// 3.4 - Return all unique triplets
vector<vector<int>> getAllUniqueTriplets(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    for (int i = 0; i < (int)nums.size() - 2; i++) {
        if (i > 0 && nums[i] == nums[i-1]) continue;
        int left = i + 1, right = nums.size() - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == target) {
                res.push_back({nums[i], nums[left], nums[right]});
                while (left < right && nums[left] == nums[left+1]) left++; // Skip left dups
                while (left < right && nums[right] == nums[right-1]) right--; // Skip right dups
                left++; right--;
            } else if (sum < target) left++;
            else right--;
        }
    }
    return res;
}

// 3.5 - Count all the triplets
int countAllTriplets(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int totalCount = 0;

    for (int i = 0; i < (int)nums.size() - 2; i++) {
        int left = i + 1, right = nums.size() - 1;
        int currentTarget = target - nums[i];

        while (left < right) {
            if (nums[left] + nums[right] == currentTarget) {
                if (nums[left] == nums[right]) {
                    int n = right - left + 1;
                    totalCount += (n * (n - 1)) / 2; 
                    break; 
                } else {
                    int leftVal = nums[left], countLeft = 0;
                    while (left < right && nums[left] == leftVal) {
                        countLeft++;
                        left++;
                    }
                    int rightVal = nums[right], countRight = 0;
                    while (right >= left && nums[right] == rightVal) {
                        countRight++;
                        right--;
                    }
                    totalCount += (countLeft * countRight);
                }
            } else if (nums[left] + nums[right] < currentTarget) {
                left++;
            } else {
                right--;
            }
        }
    }
    return totalCount;
}

// 3.6 Count all the unique triplets.
int countUniqueTriplets(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int totalCount = 0;

    for (int i = 0; i < (int)nums.size() - 2; i++) {
        // Skip duplicate pivot values
        if (i > 0 && nums[i] == nums[i-1]) continue;

        int left = i + 1, right = nums.size() - 1;
        int currentTarget = target - nums[i];

        while (left < right) {
            if (nums[left] + nums[right] == currentTarget) {
                totalCount++; // We found one unique combination
                
                // Skip all duplicate values for left and right
                int leftVal = nums[left];
                while (left < right && nums[left] == leftVal) left++;
                
                int rightVal = nums[right];
                while (right > left && nums[right] == rightVal) right--;
                
            } else if (nums[left] + nums[right] < currentTarget) {
                left++;
            } else {
                right--;
            }
        }
    }
    return totalCount;
}

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
