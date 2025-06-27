class Solution {
    struct Trie{
    Trie *child[26];
    bool isEnd;
};

public:
    void insert(Trie* root,string word){
        Trie * temp=root;
        for(char c:word){
            if(temp->child[c-'a']==NULL){
                temp->child[c-'a']=new Trie();
            }
            
            temp=temp->child[c-'a'];
        }
        temp->isEnd=true;
    }
    void solve(vector<vector<char>>& board,int row,int col, Trie* root,vector<string>& result,string word, int m,int n){
        
        if(row<0 || col <0 || row>=m || col>=n|| board[row][col]=='#')
        return;
        
            char temp=board[row][col];
            root=root->child[temp-'a'];
            if(root==NULL)
            return;
            word+=board[row][col];
            if(root->isEnd)
            {
                result.push_back(word);
                root->isEnd=false;
            }
             
            board[row][col]='#';
            solve(board,row+1,col,root,result,word,m,n);
            solve(board,row-1,col,root,result,word,m,n);
            solve(board,row,col+1,root,result,word,m,n);
            solve(board,row,col-1,root,result,word,m,n);
           board[row][col]=temp;
            
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
       
        int m= board.size();
        int n=board[0].size();
     
        Trie *root=new Trie();
        for(int i=0;i<words.size();i++){
            insert(root,words[i]);
        }
        vector<string> result;
        
            for(int i=0;i<m;i++)
                for(int j=0;j<n;j++)
                    solve(board,i,j,root,result,"",m,n);
                 

        return result;
    }
    
};