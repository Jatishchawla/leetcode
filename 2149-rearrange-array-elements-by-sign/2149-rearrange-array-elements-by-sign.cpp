class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int size = nums.size();
        vector<int> arr (size,0);
        int p = 0; // index at which next positive number should be present
        int n = 1; // index at which next negetive number should be present
        
        for(int i=0; i <nums.size(); i++){
            if(nums[i]>0){
                arr[p]=nums[i];
                p+=2;
            }
            else{
                arr[n]=nums[i];
                n+=2;
            }
        }
    return arr;
    }
};



// Problem Overview: Rearrange Array Elements by Sign
// The goal is to rearrange an array containing both positive and negative integers such that they alternate by sign (Positive, Negative, Positive, Negative, etc.) while maintaining the relative order of the elements as they appeared in the input.

// Variety 1: Equal Number of Positive and Negative Elements (0:46 - 9:45)
// Condition: The input array of size 'n' contains exactly 'n/2' positive and 'n/2' negative numbers.
// Example:
// Input: [3, 1, -2, -5, 2, -4]
// Output: [3, -2, 1, -5, 2, -4]
// Approaches:
// Brute Force Approach (0:34 - 5:48):

// Create two separate arrays (or lists): one for positive numbers and one for negative numbers.
// Iterate through the original array once to fill these two lists.
// Iterate again to place elements back into the original array: positives at even indices (0, 2, 4...) and negatives at odd indices (1, 3, 5...).
// Complexity: Time O(n), Space O(n).
// Optimal Approach (6:06 - 9:45):

// Create a new result array of size 'n'.
// Use two pointers: posIndex = 0 (for positives) and negIndex = 1 (for negatives).
// Traverse the input array once. If the current element is positive, place it at ans[posIndex] and increment posIndex by 2. If negative, place it at ans[negIndex] and increment negIndex by 2.
// Complexity: Time O(n), Space O(n).
// Variety 2: Unequal Number of Positive and Negative Elements (9:47 - 20:58)
// Condition: The count of positive and negative numbers is not equal. Remaining elements should be added at the end in their original relative order.
// Example:
// Input: [2, 3, -1, -3, 4, 5] (4 positives, 2 negatives)
// Output: [2, -1, 3, -3, 4, 5]
// Approach:
// Split and Merge (12:06 - 19:21):
// Separate all elements into two lists: positives and negatives.
// Determine the smaller count among the two lists to fill the alternating positions first.
// Use a loop to fill the alternating slots for the length of the smaller list (using the 2i and 2i + 1 pattern).
// Append the remaining elements from the larger list to the end of the array without changing their relative order.
// Complexity: Time O(n), Space O(n).