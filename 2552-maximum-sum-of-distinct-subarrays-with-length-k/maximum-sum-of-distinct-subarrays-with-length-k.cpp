class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int start=0, end=0, len=nums.size();
        unordered_map<int,int> temp;
        long long ans=0, sum=0;
        while(end<len){
            temp[nums[end]]++;
            sum+=(long long)nums[end];
            if(end-start+1>k){
                sum-=(long long)nums[start];
                temp[nums[start]]--;
                
                if(temp[nums[start]]==0)
                temp.erase(nums[start]);
                start++;
            }
            if(end-start+1==k && temp.size()==k){
            ans=max(ans,sum);
            }
        
            end++;
        }
        return ans;
    }
};