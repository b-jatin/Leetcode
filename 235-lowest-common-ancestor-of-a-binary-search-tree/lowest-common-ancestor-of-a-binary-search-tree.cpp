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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root==NULL || root==p || root==q)
        return root;
        int cur= root->val;
        if(cur<p->val && cur<q->val)
        return lowestCommonAncestor(root->right,p,q);
        else if(cur>p->val && cur>q->val)
        return lowestCommonAncestor(root->left,p,q);
        else 
        return root;

    }
};