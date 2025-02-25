class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_multiset <int> s;
        int l=nums.size();
        for (auto i: nums){
            s.insert(i);
        }
        for(int i=0;i<l;i++){
        if(s.count(nums[i])>1)
        return true;
        
        }
        return false;
    }
};