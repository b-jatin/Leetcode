class Solution {
public:
    long calculate(vector<int>& piles, int speed){
        long total=0;
        for(auto x: piles){
            total+=ceil((long  double)x/(long  double)speed);
        }
        return total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1, r=*max_element(piles.begin(),piles.end());
        int ans=INT_MAX;
        while(l<=r){
            int mid=(l+r)/2;
            long totalH=calculate(piles,mid);
            if(totalH<=h){
                ans=min(ans,mid);
                r=mid-1;
            }
            else
                l=mid+1;
        }
        return ans;
    }
};