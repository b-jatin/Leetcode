class Solution {
public:
void solve(vector<vector<int>> & answer, vector<int> & subset, int index, vector<int>& nums){
        answer.push_back(subset);
        for(int i=index;i<nums.size();i++){
            if(i!=index && nums[i]==nums[i-1])continue;
                subset.push_back(nums[i]);
                solve(answer,subset,i+1,nums);
                subset.pop_back();
        }
        
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<int> subset;
        sort(nums.begin(),nums.end());
        solve(answer,subset,0, nums);
        return answer;
    }
    
};