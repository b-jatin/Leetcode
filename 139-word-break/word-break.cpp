class Solution {
public:
bool f(unordered_set<string>& temp, string s,int start, vector<int> &dp){
    if(start==s.size())
    return true;
    if(dp[start]!=-1)return dp[start];
    for(int i=start;i<s.length();i++){
        if(temp.count(s.substr(start,i+1-start))&& f(temp,s,(i+1),dp)){
            dp[start]=true;
            return true;
        }
    }
    return dp[start]=false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> temp(wordDict.begin(),wordDict.end());
        vector<int>dp(s.length(),-1);
        return f(temp,s,0,dp);
    }
};