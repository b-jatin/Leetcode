class Solution {
public:
    void bfs(vector<vector<char>>& grid, vector<vector<int>> & visited, int row, int col, int m,int n){
        queue<pair<int,int>> q;
    q.push({row, col});
    visited[row][col] = 1;

    //vector<pair<int,int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    vector<int> rowSum={-1,0,1,0};
    vector<int> colSum={0,-1,0,1};

    while (!q.empty()) {
        int nrow = q.front().first;
        int ncol = q.front().second;
        q.pop();

        for (int i=0;i<4;i++) {
            int nnrow = nrow + rowSum[i];
            int nncol = ncol + colSum[i];
        

            if (nnrow >= 0 && nncol >= 0 && nnrow < m && nncol < n &&
                grid[nnrow][nncol] == '1' && visited[nnrow][nncol] == 0) {
                q.push({nnrow, nncol});
                visited[nnrow][nncol] = 1;
            }
        }
    }
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        vector<vector<int>> visited(m,vector<int>(n,0));

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && visited[i][j]==0){
                    count++;
                    bfs(grid,visited,i,j,m,n);
                    
                }
            }
            return count;
    }
};