class Solution {
public:
    bool solve(vector<vector<char>> & board, string&  word, int m, int n,int  row,int col, int index){
            if(index==word.size()){
                return true;
            }
            if(row<0||col<0||row>=m|| col>=n|| board[row][col]!=word[index])
                return false;
            char temp=board[row][col];
            board[row][col]='*'; //marking as visited
            bool ans1= solve(board,word,m,n, row, col+1,index+1);
            bool ans2= solve(board, word, m,n, row+1,col, index+1);
            bool ans3= solve(board, word, m,n, row-1,col,index+1 );
            bool ans4= solve(board,word, m,n, row, col-1, index+1);
            board[row][col]=temp;
            return ans1|| ans2|| ans3||ans4;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                if(solve(board,word, m,n,i,j,0)) 
                    return true;

            }

        return false;
    }
};