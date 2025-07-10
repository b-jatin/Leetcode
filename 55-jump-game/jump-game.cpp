class Solution {
public:
    bool canJump(vector<int>& nums) {
        //striver
        int maxReach=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i>maxReach)
                return false;
            maxReach=max(maxReach,nums[i]+i);
        }
        return true;
        
    }
};