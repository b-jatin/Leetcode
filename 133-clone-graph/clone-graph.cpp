/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node * dfs(unordered_map<Node*,Node*>& um,Node* cur ){
        Node * clone=new Node(cur->val);
        vector<Node*> neighbours;
        um[cur]=clone;
        for(auto temp:cur->neighbors){
            if(um.find(temp)!=um.end()){
                neighbours.push_back(um[temp]);
            }
            else{
                neighbours.push_back(dfs(um,temp));
            }
        }
        clone->neighbors=neighbours;
        return clone;
    }
    Node* cloneGraph(Node* node) {
        //solution
        if(node==NULL)
        return NULL;
        unordered_map<Node*,Node*> um;
        return dfs(um,node);
    }
};