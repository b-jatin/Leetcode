class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        int carry=1;
        n--;
        do{
            if((digits[n]+carry)==10){
                digits[n]=0;
                carry=1;
            }
            else{
                digits[n]+=carry;
                carry=0;
            }
            n--;
        }while(n>=0&&carry);
        if(carry){
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};