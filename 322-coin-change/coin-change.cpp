class Solution {
public:
    int f(int i,vector<int>& coins, int total,vector<vector<int>>& dp ){
        if(total==0){
            return 0;
        }
        if(i==0 )
        if( total%coins[0]==0)
        return total/coins[0];
        else
        return 1e9;
        if(dp[i][total]!=0)return dp[i][total];

            int notTake=f(i-1,coins,total,dp);
            int take=INT_MAX;
            if(coins[i]<=total)
            take=1+ f(i,coins,total-coins[i],dp);
            return dp[i][total]= min(take,notTake);
        
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0)
            dp[0][i]=i/coins[0];
            else
            dp[0][i]=1e9;
        }
        for(int i=1;i<n;i++)
        for(int j=0;j<=amount;j++){
            int notTake=dp[i-1][j];
            int take=INT_MAX;
            if(coins[i]<=j)
            take=1+ dp[i][j-coins[i]];
            dp[i][j]= min(take,notTake);
        }
        if(dp[n-1][amount]>=1e9){
        return -1;}

        return dp[n-1][amount];
    }
};