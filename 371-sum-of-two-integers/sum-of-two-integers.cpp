class Solution {
public:
    int getSum(int a, int b) {
        
        if(b==0)
        return a;
        unsigned int sum= a^ b, carry= a&b ;
        carry<<=1;

         return getSum(sum,carry);
    }
};