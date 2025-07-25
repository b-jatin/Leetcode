class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // algo Q( can't solve without knowing algo)
        int slow= nums[0];
        int fast=nums[0];
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);// detects cycle in the list
        slow=nums[0]; //travels linearly from from first element to start of the cycle
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow; // start of the cycle is the duplicate value
    }
};