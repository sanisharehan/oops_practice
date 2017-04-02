/**

Given a circular array (the next element of the last element is the first element of the array), print the Next Greater Number for every element. The Next Greater Number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, output -1 for this number.

Example 1:
Input: [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number; 
The second 1's next greater number needs to search circularly, which is also 2.
Note: The length of given array won't exceed 10000.

*/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // For circular lists, we use idx mod n for referring to elements.
        unordered_map<int, int> map;
        
        vector<int> result;
        // stack to store num and idx in order to account for duplicate values.
        // By stack we are actually getting min heap since numbers
        // will be saved in decreasing order only.
        stack<pair<int, int>> s;
        int last_stack_el_idx = -1;
        int size = nums.size();
        
        for (int i = 0; i < 2 * nums.size(); i++) {
            int idx = i % size;
            
            while(s.size() && s.top().first < nums[idx]) {
                map[s.top().second] = idx;
                s.pop();
            }
            
            // if stack is empty and we are adding an element, store its index.
            if (s.size() == 0) {
                last_stack_el_idx = idx;
            }
            s.push(make_pair(nums[idx], idx));
        }
        
        // Now create the result.
        result.resize(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            if (map.count(i)) {
                result[i] = nums[map[i]];
            } else {
                result[i] = -1;
            }
        }
        return result;
    }
};