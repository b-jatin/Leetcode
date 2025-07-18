class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
       // vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        vector<int> prev(m+1,0), cur(m+1,0);
       /*  for(int i=0;i<m;i++)dp[0][i]=0;
        for(int j=0;j<n;j++)dp[j][0]=0; */
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){
                    cur[j]=1+ prev[j-1];
                }
                else
                    cur[j]= max(prev[j],cur[j-1]);
            }
            prev=cur;

        }
        return cur[m];

    }
};