class Solution {
public:
    int fib(int n) {
        if(n==0 || n==1)
            return n;
        int a=0,b=1,temp=0;
        for(int i=0;i<n-1;i++){
            temp=b+a;
            a=b;
            b=temp;

        }
        return b;
    }
};