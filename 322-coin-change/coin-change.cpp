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
        vector<vector<int>> dp(n+1,vector<int>(amount+1,0));
        int ans= f(n-1,coins,amount,dp);
        if(ans>=1e9)
        return -1;
        return ans;
    }
};