// 1. Reverse a string
class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;

        while(left < right) {
            int temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }
};

// 2. Valid Palindrome (LeetCode)
class Solution {
public:
    bool isPalindrome(string s) {
       int start = 0;
       int end = s.size()-1;
       while(start < end) {
           if(!isalnum(s[start])) {
            start++; 
            continue;
           }
           if(!isalnum(s[end])) {
            end--;
            continue;
           }
           if(tolower(s[start])!=tolower(s[end]))return false;
           else{
               start++;
               end--;
           }
       }
       return true;
    }
};

// 3. Remove the duplicates from sorted array. (Displayer and scout analogy)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int i = 0; // The Displayer: marks the end of the unique elements 
        for (int j = 1; j < nums.size(); j++) { // The Scout: looks for new values  
            // If the Scout finds a new value we haven't seen yet
            if (nums[j] != nums[i]) {
                i++;             // Move to the next empty display slot
                nums[i] = nums[j]; // Copy the new value into that slot
            }
        }
        return i + 1; // Return the total count of unique elements
    }
};

// 4. Merge Sorted Array - LeetCode
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1; 
        int j = n - 1;
        int k = m + n - 1;

        while (i >= 0 && j >= 0) {
            // We want the LARGER number to go to the back
            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--; // Move the nums1 scout back
                k--; 
            } else {
                nums1[k] = nums2[j];
                j--; // Move the nums2 scout back
                k--;
            }
        }

        // If the nums2 scout still has numbers left, 
        // it means they are smaller than everything else and belong at the front.
        while (j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};
