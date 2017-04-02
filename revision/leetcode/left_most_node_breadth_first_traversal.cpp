/**
Given a binary tree, find the leftmost value in the last row of the tree.

Input:

    2
   / \
  1   3

Output:
1

Input:

        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

Output:
7

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
    int findLeftMostNode(TreeNode* root) {
        // Method 2: We can simply save just one value in result whenever there is
        // a level change.
        int level = 0;
        deque<pair<TreeNode *, int>> qu;
        vector<pair<int, int>> res;
        int result;
        
        if (root == NULL) {
            return result;
        }
        
        // Put the root in queue first.
        qu.push_back(make_pair(root, level));
        result = root->val;
        
        // Iterate till the queue doen't become empty.
        while(! qu.empty()) {
            // Get node and current level.
            TreeNode *temp = qu.front().first;
            int curr_level = qu.front().second;
            qu.pop_front();
            
            int curr_val = temp->val;
            //cout << "Value: " << curr_val << " level: " << curr_level << endl;
            // If there is a level change
            if (curr_level != level) {
                result = curr_val;
                level++;
            }
            
            if (temp->left != NULL) {
                //res.push_back(make_pair(temp->left->val, curr_level + 1));
                qu.push_back(make_pair(temp->left, curr_level+1));
                //cout << "Left is there" << endl;
            }
            
            if (temp->right) {
                //res.push_back(make_pair(temp->right->val, curr_level + 1));
                qu.push_back(make_pair(temp->right, curr_level+1));
            }
        }
        return result;
        /*
        // Chances there are only right nodes.
        if (res.size() == 0) {
            return root->val;
        }
        
        // If only one node is there.
        if (res.size() == 1) {
            return res[0].first;
        }
        
        int max_level = res[res.size() - 1].second;
        int left_most_val = res[res.size() - 1].first;
        
        // All left nodes value and their levels should be saved in res.
        // Iterate from back and the first left node where the level change occurs.
        for (int i = res.size() - 2; i >= 0; i--) {
            if (res[i].second != max_level) {
                left_most_val = res[i+1].first;
                return left_most_val;
            }
        }
        return res[0].first;
        */
        /*
        // We can do the breadth first traversal here to find the left nodes and their levels.
        // Then get the leftmost node and its corresponding level.
        int level = 0;
        deque<pair<TreeNode *, int>> qu;
        vector<pair<int, int>> res;
        int result;
        
        if (root == NULL) {
            return result;
        }
        
        // Put the root in queue first.
        qu.push_back(make_pair(root, level));
        
        // Iterate till the queue doen't become empty.
        while(! qu.empty()) {
            // Get node and current level.
            TreeNode *temp = qu.front().first;
            int curr_level = qu.front().second;
            
            int curr_val = temp->val;
            qu.pop_front();
            
            //cout << "Value: " << curr_val << " level: " << curr_level << endl;
            
            if (temp->left != NULL) {
                res.push_back(make_pair(temp->left->val, curr_level + 1));
                qu.push_back(make_pair(temp->left, curr_level+1));
                //cout << "Left is there" << endl;
            }
            
            if (temp->right) {
                res.push_back(make_pair(temp->right->val, curr_level + 1));
                qu.push_back(make_pair(temp->right, curr_level+1));
            }
        }
        
        // Chances there are only right nodes.
        if (res.size() == 0) {
            return root->val;
        }
        
        // If only one node is there.
        if (res.size() == 1) {
            return res[0].first;
        }
        
        int max_level = res[res.size() - 1].second;
        int left_most_val = res[res.size() - 1].first;
        
        // All left nodes value and their levels should be saved in res.
        // Iterate from back and the first left node where the level change occurs.
        for (int i = res.size() - 2; i >= 0; i--) {
            if (res[i].second != max_level) {
                left_most_val = res[i+1].first;
                return left_most_val;
            }
        }
        return res[0].first;
        */
    }
};