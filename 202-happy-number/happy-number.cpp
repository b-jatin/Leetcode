class Solution {
public:
    int newNumber(int n){
        int num=0;
        while(n){
            int temp=n%10;
            num+=temp*temp;
            n=n/10;
        }
        return num;
    }
    bool isHappy(int n) {
        unordered_set<int> seen;
        while(n!=1 && !seen.count(n)){
            seen.insert(n);
            n=newNumber(n);
        }
        return n==1;
    }
};