/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversalOG(TreeNode* root) { // original solution
        if (!root) { return {}; }
        
        vector<int> left = inorderTraversal(root->left);
        vector<int> right = inorderTraversal(root->right);
        left.push_back(root->val);
        for (auto it = right.begin(); it != right.end(); it++) {
            left.push_back(*it);
        }
        return left;
    }
    
    void recHelper(TreeNode* root, vector<int>& result) {
        if (!root) {
            return;
        }
        recHelper(root->left, result);
        result.push_back(root->val);
        recHelper(root->right, result);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        recHelper(root, result);
        return result;
    }
};