class Solution {
public:
    int reverse(int x) {
        if(!x)
        return x;
        int ans=0;
        while(x){
            if(ans>INT_MAX/10 || ans<INT_MIN/10)return 0;
            ans=(10*ans)+(x%10);
            x/=10;

        }
       
        return int(ans);
    }
};