class Solution {
public:
    int findMin(vector<int>& nums) {
        int n= nums.size();
        int left=0,right=n-1,mid=0,ans=INT_MAX;
        while(left<=right){
            mid = left+ (right-left)/2;
            if(nums[left]<=nums[mid]){
                ans=min(ans,nums[left]);
                left=mid+1;
            }
            else{
                ans=min(ans,nums[mid]);
                right=mid-1;

            }
        }
        return ans;
    }
};