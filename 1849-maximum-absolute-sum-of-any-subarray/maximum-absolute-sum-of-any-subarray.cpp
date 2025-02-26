class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n=nums.size(),max=0,min=0,sum=0;
        for(auto i:nums){
            sum+=i;
            if(sum>max)max=sum;
            if(sum<min)min=sum;
        }
      /*  int n=nums.size(),sum=0,m=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                for(int k=i;k<=j;k++){
                    sum+=(nums[k]);
                    
                }
                m=max(m,abs(sum));
                sum=0;
            }
        }*/
        return abs(max-min);
    }
};