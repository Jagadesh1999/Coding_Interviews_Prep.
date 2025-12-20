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
