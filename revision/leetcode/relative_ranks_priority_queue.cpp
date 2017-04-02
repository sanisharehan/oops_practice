/**

Given scores of N athletes, find their relative ranks and the people with the top three highest scores, who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".

Example 1:
Input: [5, 4, 3, 2, 1]
Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
Explanation: The first three athletes got the top three highest scores, so they got "Gold Medal", "Silver Medal" and "Bronze Medal". 
For the left two athletes, you just need to output their relative ranks according to their scores.
Note:
N is a positive integer and won't exceed 10,000.
All the scores of athletes are guaranteed to be unique.
*/

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        // Method 2: One of the widely used data structure for relative ranking/getting maximum number
        // is priority queue.This gives us sorting by default. O(nlogn) since
        // heap DS is used.
        
        vector<string> result;
        result.resize(nums.size());
        priority_queue<pair<int, int>> q;
        
        for (int i =0; i <nums.size() ; i++) {
            q.push(make_pair(nums[i], i));
        }
        
        for (int i = 1; i <= nums.size(); i++) {
            int idx = q.top().second;
            string value;
            switch(i) {
                case 1: value = "Gold Medal";
                        break;
                case 2: value = "Silver Medal";
                        break;
                case 3: value = "Bronze Medal";
                        break;
                default: value = to_string(i);
            }
            result[idx] = value;
            q.pop();
        }
        return result;
        
        
        /*
        // Method 1: We created a map storing number and the original indices. Then
        // sorted the original vector in descending order and got results.
        vector<string> result;
        result.resize(nums.size());
        unordered_map<int, int> map;
        
        // Add the numbers and their corresponding indices.
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]] = i;
        }
        
        // Now reverse sort the initial array.
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        
        for (int i = 1; i <= nums.size(); i++ ) {
            int idx = map[nums[i-1]];
            string value;
            switch(i) {
                case 1: value = "Gold Medal";
                        break;
                case 2: value = "Silver Medal";
                        break;
                case 3: value = "Bronze Medal";
                        break;
                default: value = to_string(i);
            }
            result[idx] = value;
        }
        return result;
        */
        
    }
};