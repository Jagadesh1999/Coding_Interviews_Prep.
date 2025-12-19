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
