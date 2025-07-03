class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n<2)
        return n?nums[0]:0;
        return max(robber(nums,0,n-2), robber(nums,1,n-1));
        }

    int robber(vector<int>& nums,int left,int right){
        int prev=0,cur=0;
        for(int i=left;i<=right;i++){
            int temp=max(cur,nums[i]+prev);
            prev=cur;
            cur=temp;
        }
        return cur;
    }
    
};