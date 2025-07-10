class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n=intervals.size();
        if(n<=1)
        return intervals;
        sort(intervals.begin(),intervals.end()); 
        vector<int> temp=intervals[0]; // take 1st interval for comparison
        
            for(auto i:intervals){
                if(temp[1]>=i[0]){
                    temp[1]=max(temp[1],i[1]);
                }
                else{
                    ans.push_back(temp);
                    temp=i;
                }
                
        }
        ans.push_back(temp);// adding the last element
        return ans;
        
    }
};