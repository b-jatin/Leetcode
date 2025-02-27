class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n= prices.size(),sell=0, buy=prices[0];
        for(int i=1;i<n;i++){
            if(prices[i]>buy){
                sell=max(prices[i]-buy,sell);  
            }
            else if(prices[i]<buy){
                buy=prices[i];
            }
        }

        return sell;
        
    }
};