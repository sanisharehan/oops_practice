/**
Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Note: The length of the given binary array will not exceed 50,000.

*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // Method: Basically we start from first and count the number of 0s and 1s by adding them
        // so that their final sum == 0 (0 is replaced by -1).
        // Then find the maximum length substring with sum == 0 which means the number of 1s and 0s are now same.
        // Complexity : o(n)
        
        int result = 0;
        int sum = nums.size(); // take initial sum as array size.
        int size = nums.size();
        // Creating an array to store what sum is obtained at which elements count.
        // We are making the size as 2*size + 1 to accomodate unique sum values from range 0 - 2*sum.
        int balance[2 * size + 1] = {};
        
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i] == 0 ? -1 : 1;
            
            if (sum == size) {
                // This means number of 0s and 1s are balanced out.
                result = i+1;
            } else {
                if (balance[sum] != 0) {
                    // This means the sum has repeated in traversal. Hence between the last index
                    // where sum occurred and this new index, the count of 0s and 1s is same.
                    result = max(result, i + 1 - balance[sum]);
                } else {
                    balance[sum] = i+1;
                }
            }
        }
        return result;
        
        
        /*
        int count_0 = 0;
        int count_1 = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                count_0++;
            } else {
                count_1++;
            }
        }
        
        int extra = count_1 - count_0;
        int num_del = -1;
        
        if (extra == 0) {
            return nums.size();
        }
        
        // if extra is +ve, it means 1s are more else 0s.
        if (extra > 0) {
            num_del = 1;
        } else {
            num_del = 0;
        }
        
        extra = extra < 0 ? extra * (-1): extra;
        
        int rem = 0;
        int first_index = 0;
        int last_index = nums.size() - 1;
        int f_idx = 0, b_idx = 0;
        bool front_rem = true;
        
        while (rem < extra) {
            if (front_rem) {
                if (nums[f_idx] == num_del) {
                    first_index = f_idx+1;
                    rem++;
                    f_idx++;
                    front_rem = true;
                    continue;
                } else {
                    if (nums[nums.size()-b_idx-1] == num_del) {
                        last_index = (nums.size() - b_idx - 2);
                        b_idx++;
                        rem++;
                        front_rem = false;
                        continue;
                    } else {
                        f_idx++;
                        b_idx++;
                    }
                }
            } else {
                if (nums[nums.size()-b_idx-1] == num_del) {
                    last_index = (nums.size() - b_idx - 2);
                    b_idx++;
                    rem++;
                    front_rem = false;
                    continue;
                } else {
                    if (nums[f_idx] == num_del) {
                    first_index = f_idx+1;
                    rem++;
                    f_idx++;
                    front_rem = true;
                    continue;
                } else {
                        f_idx++;
                        b_idx++;
                    }
                }
            }
        }
        
        int result = last_index - first_index + 1;
        return result;
        */
        
    }
};
