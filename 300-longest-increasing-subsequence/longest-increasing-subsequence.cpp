class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //from solutions
        int n=nums.size();
        if(n<=1)
        return n?1:0;
        
        vector<int> dp(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++)
            if(nums[i]>nums[j]){
            dp[i]=max(1+ dp[j],dp[i]);
            }
           
        }


        return *max_element(dp.begin(),dp.end());
    }
};