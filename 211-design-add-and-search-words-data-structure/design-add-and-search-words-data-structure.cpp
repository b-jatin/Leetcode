class WordDictionary {

struct Trie{
    Trie *child[26];
    bool isEnd;
};
private:
    Trie* root;
public:
    
    WordDictionary() {
        root =new Trie();
    }
    
    void addWord(string word) {
        Trie * temp=root;
        for(char c:word){
            if(temp->child[c-'a']==NULL){
                temp->child[c-'a']=new Trie();
            }
            
            temp=temp->child[c-'a'];
        }
        temp->isEnd=true;
    }
    bool dfs(Trie* root, string word, int index){
        if(index==word.size()&& root->isEnd)
        return true;
        if(index==word.size()&& !root->isEnd)
        return false;

        if(word[index]=='.'){
            for(int i=0;i<26;i++){
                if(root->child[i]!=NULL)
                    if(dfs(root->child[i], word,index+1))
                        return true;
                
            }
            return false;
        }
        else{
            if(root->child[word[index]-'a']==NULL)
                return false;
                return dfs(root->child[word[index]-'a'],word, index+1);
        }
    }

    bool search(string word) {
        return dfs(root,word,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */