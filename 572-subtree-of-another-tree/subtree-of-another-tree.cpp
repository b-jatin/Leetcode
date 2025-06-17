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

    bool dfs(TreeNode* r, TreeNode* s){
            if(r==NULL && s==NULL)
            return true;
            if(r==NULL || s==NULL)
            return false;
            if(r->val!=s->val)
            return false;
            return dfs(r->left,s->left) && dfs(r->right, s->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        if(root==NULL)
        return false;
        if(dfs(root, subRoot))
        return true;
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
        

        
    }
};