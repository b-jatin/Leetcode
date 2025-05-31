class Solution {
public:
    int climbStairs(int n) {
       // vector<int> dp(n+1,0);
       int prev=1;
        int prev2=2;
        if(n==1||n==2)
        return n;
        for(int i=3;i<=n;i++){
            //dp[i]=dp[i-1]+dp[i-2];
            int cur=prev2+prev;
            prev=prev2;
            prev2=cur;
        }
        return prev2;


    }
};