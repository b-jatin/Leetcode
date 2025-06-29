class Solution {
public:
    void dfs(int row, int col,int height,set<pair<int,int>> & s,vector<vector<int>>& heights,int m, int n){
        if(row<0 ||col<0|| row>=m|| col>=n|| heights[row][col]<height)
        return;
        if(s.count({row,col}))
        return;
        s.insert({row,col});
        dfs(row+1,col,heights[row][col],s,heights,m,n);
        dfs(row-1,col,heights[row][col],s,heights,m,n);
        dfs(row,col+1,heights[row][col],s,heights,m,n);
        dfs(row,col-1,heights[row][col],s,heights,m,n);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        //Neetcode solution
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>> ans;
        set<pair<int,int>> pac,atl;

        for(int col=0;col<n;col++){
            dfs(0,col,heights[0][col],pac,heights,m,n);
            dfs(m-1,col,heights[m-1][col],atl,heights,m,n);
        }
        for(int row=0;row<m;row++){
            dfs(row,n-1,heights[row][n-1],atl,heights,m,n);
            dfs(row,0,heights[row][0],pac,heights,m,n);
        }

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                if(pac.count({i,j}) && atl.count({i,j}))
                    ans.push_back({i,j});
            }
        return ans;
    }
};