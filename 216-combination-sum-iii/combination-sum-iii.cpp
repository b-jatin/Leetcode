class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> substr;
        solve(result,substr,k,n,1);
        return result;
    }

    void solve(vector<vector<int>>& result, vector<int>& substr, int k, int n, int index){
        if(n==0 && substr.size()==k){
            result.push_back(substr);
            return;
        }
        if(k<substr.size() ||n<0)
        return;
        for(int i=index; i<10;i++){
            
            substr.push_back(i);
            solve(result,substr,k,n-i,i+1);
            substr.pop_back();

        }

    }
};