class Solution {
public:
    int f(int m,int n, int i,int j,vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i==m-1 && j==n-1)
        return grid[i][j];
        if(i<0 || j<0|| i>=m || j>=n)
        return INT_MAX;
        if(dp[i][j]!=0)
        return dp[i][j];
        //int sum= 0;
        dp[i][j]+=grid[i][j];
        dp[i][j]+=min(f(m,n,i+1,j, grid,dp), f(m,n,i,j+1,grid,dp));
        return dp[i][j];


    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        return f(m,n,0,0, grid, dp );
        
    }
};