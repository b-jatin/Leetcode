class Solution {
public:
    int f(int i,int j,vector<int>& cuts,vector<vector<int>>& dp ){
    if( i>j )
    return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int mini=INT_MAX;
    for(int x=i;x<=j;x++){
    int cost=cuts[j+1]- cuts[i-1]+f(i,x-1,cuts,dp) + f(x+1,j,cuts,dp);
        mini=min(mini,cost);
    }
    return dp[i][j]=mini;

    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.push_back(0);
        sort(cuts.begin(),cuts.end());
        int len=cuts.size();
        vector<vector<int>> dp(len,vector<int>(len,-1));
        return f(1,len-2,cuts,dp);
    }
};