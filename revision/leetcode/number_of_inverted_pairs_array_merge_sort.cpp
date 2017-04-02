/**

Given an array nums, we call (i, j) an important reverse pair if i < j and nums[i] > 2*nums[j].

You need to return the number of important reverse pairs in the given array.

Example1:

Input: [1,3,2,3,1]
Output: 2
Example2:

Input: [2,4,3,5,1]
Output: 3
Note:
The length of the given array will not exceed 50,000.
All the numbers in the input array are in the range of 32-bit integer.


*/


class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int result;
        if (nums.size() == 0) {
            return 0;
        }
        
        int start = 0;
        int end = nums.size() - 1;
        result = merge_sort(nums, start, end);
        return result;
    }
    
    int
    merge_sort(vector<int> &nums, int start, int end) {
        if (start == end) {
            return 0;
        }
        
        int mid = (start+end)/2;
        int count1 = merge_sort(nums, start, mid);
        int count2 = merge_sort(nums, mid+1, end);
        
        int i = start, j = mid + 1;
        int count = 0;
        
        // We use the merge sort here. Basically when comparing the two
        // small portions, 6 7 8 and 2 3 9, the indices of first part are smaller
        // than the indices of second part i.e. i < j.
        // We look if a[i] > 2*a[j]. If yes, all the numbers from i to mid will
        // satisfy this condition only.
        while (i <= mid && j <= end) {
            if ((long) nums[i] > (long) 2*nums[j]) {
                j++;
                count += mid - i + 1;
            } else {
                i++;
            }
        }
        
        // Once the count is obtained from the original portion,
        // sort it.
        sort(nums.begin() + start, nums.begin() + end + 1);
        return (count + count1 + count2) ;
    }
    
};