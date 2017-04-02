/**

You need to find the largest value in each row of a binary tree.

Example:
Input: 

          1
         / \
        3   2
       / \   \  
      5   3   9 

Output: [1, 3, 9]

Hint: We did breadth first traversal. Queue is the data structure used in this case.
*/



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> findValueMostElement(TreeNode* root) {
        int level = 0;
        int max = -1;
        vector<int> result;
        
        if (root == NULL) {
            return result;
        }
        
        
        deque<pair<TreeNode*, int>> qu;
        
        qu.push_back(make_pair(root, level));
        max = root->val;
        
        // While queue is not empty.
        while (! qu.empty()) {
            TreeNode *temp = qu.front().first;
            int curr_level = qu.front().second;
            qu.pop_front();
            
            int curr_val = temp->val;
            
            // Means there is a level change.
            if (curr_level != level) {
                result.push_back(max);
                level++;
                max = curr_val;
            } 
            if (curr_val > max) {
                max = curr_val;
            }
            //cout << "Node: " << curr_val << " level: " << curr_level << endl;
            if (temp->left != NULL) {
                qu.push_back(make_pair(temp->left, curr_level+1));
            }
            if (temp->right != NULL) {
                qu.push_back(make_pair(temp->right, curr_level+1));
            }
        }
        result.push_back(max);
        return result;
    }
};
