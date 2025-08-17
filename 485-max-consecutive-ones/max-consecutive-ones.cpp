class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int end=0,start=0,n=nums.size(),ans=INT_MIN;
        int count=0;
        while(end<n){
            
            if(nums[end]==1){
                count++;
            }
            else{
                count=0;
                start=end+1;
            }
            ans=max(ans,count);
            end++;
        }
        return ans;
    }
};