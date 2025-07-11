class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> ans;
        int top=0, bottom=m-1,left=0, right=n-1;

        while(top<=bottom && left<=right){
            //go right
            for(int i=left;i<=right;i++){
                ans.push_back(matrix[top][i]);
            }
            top++;
            if(top<=bottom){
            for(int i=top;i<=bottom;i++){// go down
                ans.push_back(matrix[i][right]);
            }
            right--;
            }
            if(top<=bottom){
            for(int i=right;i>=left;i--) //go left
            {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
            }
            if(left<=right){
            for(int i=bottom;i>=top;i--){// go up
                ans.push_back(matrix[i][left]);
            }
            left++;
            }
        }

        return ans;
    }
};