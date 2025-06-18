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
    bool BST(TreeNode* root, long long left, long long right){
        if(root==NULL)//base
        return true;
        if(root->val<right && root->val > left)
        {
            return BST(root->left,left,root->val) && BST(root->right, root->val,right);
        }
        else 
        return false;
}
    bool isValidBST(TreeNode* root) {
        return BST(root, LONG_MIN, LONG_MAX);
    }
};