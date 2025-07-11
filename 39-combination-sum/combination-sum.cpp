class Solution {
public:
    void solve(vector<int>& candidates, int target, vector<vector<int>>& ans,vector<int> & temp,int index){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(index>=candidates.size()|| target<0)
        return;

        temp.push_back(candidates[index]);
        solve(candidates,target-candidates[index],ans,temp,index);
        temp.pop_back();
        solve(candidates,target,ans,temp,index+1);



    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
     solve( candidates,target, ans, temp,0);
     return ans;
    }
};