class Solution {
public:
    int bfs(vector<vector<int>>& grid, int i,int j,int n,int m){
        int area=1;
        queue<pair<int,int>> q;
        q.push({i,j});
        grid[i][j]=0;
        
        while(!q.empty()){
            int row= q.front().first;
            int col=q.front().second;
            q.pop();
           
            vector<int> r={0,1,0,-1};
            vector<int> c={1,0,-1,0};
            for(int i=0;i<4;i++){
                int newrow=row+r[i];
                int newcol=col+c[i];
                if(newrow>=0 && newcol>=0 && newrow<n && newcol<m && grid[newrow][newcol]==1 )
{
    q.push({newrow,newcol});
     grid[newrow][newcol]=0;
            area++;
}            }
            


        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int maxArea=0;
      
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    maxArea=max(maxArea,bfs(grid,i,j,n,m));
                    
                }
            }
        }
        return maxArea;
    }
};