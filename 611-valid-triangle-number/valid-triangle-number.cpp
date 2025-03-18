class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count=0,len=nums.size();
        
        if(len<3){
            return 0;
        }
        for(int i=len-1;i>=2;i--){
            int left=0, right=i-1;
            while(left<right){
            if(nums[left]+nums[right]>nums[i]){
                count+=right-left;
                right--;
                
            }
            else{
                left++;
            }
            }
        }
        return count;
    }
};