class Solution {
public:
    int hammingWeight(int n) {
        int rem=0;
        while(n){
            if(n%2==1)
            rem++;
            n=n/2;
        }
        return rem;
    }
};