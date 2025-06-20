class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int len=matrix.size();
        for(int i=0,x=len-1;i<x;i++,x--){
            for(int j=0;j<len;j++){
                swap(matrix[i][j],matrix[x][j]);
            }
        }

        for(int i=0;i<len;i++){
            for(int j=i+1;j<len;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
};