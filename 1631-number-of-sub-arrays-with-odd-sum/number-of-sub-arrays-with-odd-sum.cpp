class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int odd=0,even=0,answer=0;
        for(auto number:arr){
            if(number%2==0)even++;
            else{
                swap(odd,even);
                odd++;
            }
            answer=(int)(answer+odd)%(int)1000000007;
        }
        return answer;
    }
};