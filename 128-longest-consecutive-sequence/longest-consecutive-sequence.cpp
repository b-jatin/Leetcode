class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
        return 0;
        int m=1;
        unordered_set<int> temp;
        for(int i=0; i<n;i++){
            temp.insert(nums[i]);
        }

        for(auto j: temp){
            if(temp.find(j-1)==temp.end()){
                int count=1;
                int x=j;
                while(temp.find(x+1)!=temp.end()){
                    
                    x++;
                    count++;
                }
                
                    m=max(count,m);
                
            }
        }
        return m;
    }
};