class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //striver solution
        int m= grid.size();
        int n=grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int fresh=0;
        queue<pair<pair<int,int>,int>> q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    visited[i][j]=2;
                }
                else{
                    visited[i][j]=0;
                    
                }
                if(grid[i][j]==1)
                fresh++;

            }
        }

        int timeMax=0;
        int deltaR[]={-1,0,1,0};
        int deltaC[]={0,-1,0,1};
        int count=0;
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int time=q.front().second;
            timeMax=max(timeMax,time);
            int node=grid[row][col];
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+deltaR[i];
                int ncol=col+deltaC[i];
                if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && visited[nrow][ncol]==0 && grid[nrow][ncol]==1)
                { 
                    q.push({{nrow,ncol},time+1});
                    visited[nrow][ncol]=2;
                    count++;
                }
            }
        }
        if(fresh!=count)
        return -1;
        return timeMax;
    }
};