class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> temp;
        int s= nums.size();

        for(int i=0;i<s;i++){
            temp[nums[i]]=i;
        }

        for(int i=0;i<s;i++)
        {
            int comp= target-nums[i];
            if(temp.count(comp)&& temp[comp]!=i){
                return {i,temp[comp]};
            }
        }
        return {};
    }
};