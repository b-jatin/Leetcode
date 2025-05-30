class Solution {
public:
    bool isPalindrome(int x) {
        long temp=0,y=x;
        if(x<0)
        return false;
        while(x){
            long rem=0;
            rem=x%10;
            temp=10*temp+rem;
            x/=10;
        }
        if(temp==y)
        return true;
        return false;
    }
};