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
    void height(vector<int> & result, TreeNode* root, int level){
        if(root==NULL)
        return;
        if(level==result.size())
            result.push_back(root->val);
        height(result,root->right,level+1);
        height(result,root->left,level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        height(result,root,0);
        return result;
    }
};