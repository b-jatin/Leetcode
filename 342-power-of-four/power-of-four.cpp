class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==1)
        return true;
        else if(n<=0)return false;
        else if(n%2==1)
        return false;
        else{
            double temp=log(n)/log(4);
            return (temp==(int)temp);
        }
        return false;
    }
};