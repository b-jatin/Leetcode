class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        solve(result, nums,0, subset);
        return result;
    }

    void solve(vector<vector<int>>& result, vector<int>& nums,int index,vector<int>& subset ){
        if(index==nums.size()){
            result.push_back(subset);
            return;
        }
        subset.push_back(nums[index]);
        solve(result,nums, index+1,subset);

        subset.pop_back();
        solve(result, nums, index+1, subset);
    }
};