class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;

        while (left < right) {
            int currentArea = min(height[left], height[right]) * (right - left);
            maxArea = max(maxArea, currentArea);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxArea;
       /* int n= height.size(),area=0,m=INT_MIN;
        int j=n-1;

        for( int i=0;i<n;i++){
            while(i!=j){
                
                if(height[i]> height[j]){
                    area=height[j]*(j-i);
                    m=max(area,m);
                    
                }
                else{
                    area=height[i]*(j-i);
                    m=max(area,m);
                }
                area=0;
                j--;
            }
            j=n-1;
        }
        return m;*/

    }
};