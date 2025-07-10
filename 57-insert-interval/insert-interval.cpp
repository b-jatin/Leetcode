class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int start=newInterval[0];
        int end=newInterval[1];
        int n=intervals.size();
        vector<vector<int>> ans;
        int i=0;
            while(i<n&& intervals[i][1]<start){ // left non overlapping portion
                ans.push_back(intervals[i]);
                i++;
        }
            while(i<n && intervals[i][0]<=end){
                newInterval={min(intervals[i][0], newInterval[0]), max(intervals[i][1],newInterval[1])};
                i++;
            }
            ans.push_back(newInterval);
        
            while(i<n && intervals[i][0]>end){// right non overlapping portion
                ans.push_back(intervals[i]);
                i++;
            }
            return ans;
    }
};