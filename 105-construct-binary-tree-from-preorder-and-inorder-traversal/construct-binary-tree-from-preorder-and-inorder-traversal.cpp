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
    TreeNode* solve(vector<int>& preorder,int prestart, int preend, vector<int>& inorder,int instart, int inend, unordered_map<int,int>& mp){
        // striver solution
        if( prestart>preend || instart>inend )
        return NULL;

        TreeNode* temp= new TreeNode(preorder[prestart]);
        int inroot=mp[preorder[prestart]];
        int numleft=inroot-instart;
        temp->left=solve(preorder,prestart+1,prestart+numleft,inorder,instart,inroot-1,mp);
        temp->right=solve(preorder,prestart+numleft+1,preend,inorder,inroot+1,inend,mp);
        return temp;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return solve(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
    }

};