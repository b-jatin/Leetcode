class Solution {
public:
    
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            if(!visited[0][i] && board[0][i]=='O'){
                q.push({0,i});
                visited[0][i]=1;
            }
            if(!visited[n-1][i] &&board[n-1][i]=='O'){
                q.push({n-1,i});
                visited[n-1][i]=1;
            }
        }
            for(int j=0;j<n;j++){
                if(!visited[j][0] &&board[j][0]=='O'){
                q.push({j,0});
                visited[j][0]=1;
                }
                if(!visited[j][m-1] &&board[j][m-1]=='O'){
                    q.push({j,m-1});
                    visited[j][m-1]=1;
                }
            }
        
        
        vector<int> r={0,1,0,-1};
        vector<int> c={1,0,-1,0};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+ r[i];
                int ncol=col+ c[i];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !visited[nrow][ncol] && board[nrow][ncol]=='O')
            {
                visited[nrow][ncol]=1;
                q.push({nrow,ncol});
            }   
            }
        }
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(!visited[i][j] && board[i][j]=='O')
                board[i][j]='X';
        }
    
    }
};