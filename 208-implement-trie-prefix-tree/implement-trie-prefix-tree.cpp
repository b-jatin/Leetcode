class Trie {
struct TrieNode{
    TrieNode *child[26];
    bool isEnd;
};
private: 
    TrieNode* root;
public:
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode * temp=root;
        for(char c:word){
            if(temp->child[c-'a']==NULL)
                temp->child[c-'a']=new TrieNode();
            temp=temp->child[c-'a'];
        }
        temp->isEnd=true;
    }
    
    bool search(string word) {
        TrieNode * temp=root;
        for(char c:word){
            if(temp->child[c-'a']==NULL)
                return false;
            temp=temp->child[c-'a'];
        }
        return (temp->isEnd);
    }
    
    bool startsWith(string prefix) {
        TrieNode * temp=root;
        for(char c:prefix){
            if(temp->child[c-'a']==NULL)
                return false;
            temp=temp->child[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */