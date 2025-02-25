class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n);
        vector<int> left(n,1);
        vector<int> right(n,1);
        left[0]=nums[0];
        right[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            left[i]=left[i-1] * nums[i];
            
        }
        for(int i=n-2;i>=0;i--){
            right[i] =right[i+1]* nums[i];
        }

        for(int i=0; i<n;i++){
            if(i==0){
                output[i]=right[i+1];
            }
            else if(i==n-1){
                output[i]=left[i-1];
            }
            else{
            output[i]=left[i-1]*right[i+1];
            }
        }
        return output;
        /*for(int i=0; i<n; i++){
            int product = 1;
            for(int j=0; j<n; j++){
                if(i == j) continue;
                product *= nums[j];
            }
            output.push_back(product);
        }
        return output;*/
    }
};