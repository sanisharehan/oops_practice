
/**

You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2. Find all the next greater numbers for nums1's elements in the corresponding places of nums2.

The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. If it does not exist, output -1 for this number.

Example 1:
Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
Output: [-1,3,-1]
Explanation:
    For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
    For number 1 in the first array, the next greater number for it in the second array is 3.
    For number 2 in the first array, there is no next greater number for it in the second array, so output -1.

*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        /* Method 1: Original
        // First put the elements of nums in an unordered map alongwith
        // the indices for easy lookup.
        vector<int> result;
        unordered_map<int, int> num_map;
        for (int i = 0; i < nums.size(); i++) {
            num_map[nums[i]] = i;
        }
        
        // Now for each element in findNums, search the index in nums
        // and then find the greater number to its right in nums.
        for (int i = 0; i < findNums.size(); i++) {
            unordered_map<int, int>::iterator m_it = num_map.find(findNums[i]);
            int idx = m_it->second;
            int number = -1;
            
            for (int j = idx+1; j < nums.size(); j++) {
                if (nums[j] > nums[idx]) {
                    number = nums[j];
                    break;
                }
            }
            result.push_back(number);
        }
        return result;
        */
        // Method 2: Faster. DS used: Stack for reducing the n2 complexity of finding
        // the largest nuber to the right of a given number.
        // Map is used to store the largest number for a given number.
        stack<int> num_s;
        unordered_map<int, int> num_m;
        vector<int> result;
        
        // We are creating a map here.
        for (int i = 0; i < nums.size(); i++) {
            while(num_s.size() && num_s.top() < nums[i]) {
                num_m[num_s.top()] = nums[i];
                num_s.pop();
            }
            num_s.push(nums[i]);
        }
        
        for (int i = 0; i < findNums.size(); i++) {
            if (num_m.count(findNums[i])) {
                result.push_back(num_m[findNums[i]]);
            } else {
                result.push_back(-1);
            }
        }
         return result;
    }
};