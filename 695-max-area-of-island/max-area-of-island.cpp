class Solution {
public:
    int bfs(vector<vector<int>>& grid, vector<vector<int>> & visited, int i,int j,int n,int m){
        int area=0;
        queue<pair<int,int>> q;
        q.push({i,j});
        visited[i][j]=1;
        while(!q.empty()){
            int row= q.front().first;
            int col=q.front().second;
            q.pop();
            
            area++;
            vector<int> r={0,1,0,-1};
            vector<int> c={1,0,-1,0};
            for(int i=0;i<4;i++){
                int newrow=row+r[i];
                int newcol=col+c[i];
                if(newrow>=0 && newcol>=0 && newrow<n && newcol<m && grid[newrow][newcol]==1 && visited[newrow][newcol]!=1)
{
    q.push({newrow,newcol});
    visited[newrow][newcol]=1;
}            }
            


        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int maxArea=0;
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0 && grid[i][j]==1){
                    maxArea=max(maxArea,bfs(grid,visited,i,j,n,m));
                    
                }
            }
        }
        return maxArea;
    }
};