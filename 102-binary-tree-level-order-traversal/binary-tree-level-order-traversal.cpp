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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL)
        return {};
        vector<vector<int>> result;
        vector<int> sub;
        bfs(result,root);
        return result;
        
    }

    void bfs(vector<vector<int>>& result, TreeNode* root){
            queue<TreeNode*> q;
            q.push(root);

            while(!q.empty()){
                vector<int> level;
                int len=q.size();
                for(int i=0;i<len;i++){
                TreeNode* temp= q.front();
                q.pop();
                level.push_back(temp->val);

                if(temp->left!=NULL){
                    q.push(temp->left);
                }
                if(temp->right!=NULL){
                    q.push(temp->right);
                }
            }
            result.push_back(level);
            }

    }
};