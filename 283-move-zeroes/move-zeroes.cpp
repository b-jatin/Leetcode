class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int slow=0,len=nums.size();
        if(len<=1)return;
        for(int fast=0;fast<len;fast++){
            if(nums[fast]!=0 ){
                swap(nums[slow],nums[fast]);
                slow ++;
            }
        }
    }
};