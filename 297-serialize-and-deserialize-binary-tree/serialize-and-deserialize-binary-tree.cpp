/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void solve1(TreeNode* root,stringstream & temp){
        if(root==NULL){
        temp<< "N ";
        return;
        }
        temp<<root->val<<" ";
        solve1(root->left,temp);
        solve1(root->right,temp);


    }
    TreeNode* solve2(stringstream& ss){
        string temp="";
        ss>>temp;
        if(temp=="N")
        return NULL;
        TreeNode* root=new TreeNode(stoi(temp));
        root->left=solve2(ss);
        root->right=solve2(ss);
        return root;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream temp;
        solve1(root,temp);
        return temp.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return solve2(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));