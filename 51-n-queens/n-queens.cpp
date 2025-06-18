class Solution {
public:
    
    bool isValid(int row, int col, vector<string>&sub, int n){
        int temprow= row;
        int tempcol=col;
        while(row>=0 && col>=0){
            if(sub[row][col]=='Q')
            return false;
            row--;
            col--;
        }
        row=temprow;
        col=tempcol;
        while(col>=0){
            if(sub[row][col]=='Q')
                return false;
                col--;
        }
        row=temprow;
        col=tempcol;
        while(row<n && col>=0){
            if(sub[row][col]=='Q')
            return false;
            row++;
            col--;
        }
        return true;
    }
    void solve(vector<vector<string>>& result, vector<string>& sub, int n, int col){
        if(col==n){
            result.push_back(sub);
            return;
        }
        for(int row=0;row<n;row++){
            if(isValid(row,col,sub, n)){
                    sub[row][col]='Q';
                    solve(result,sub,n,col+1);
                    sub[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> sub(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
        sub[i]=s;
        solve(result,sub,n,0);
        return result;
    }

};