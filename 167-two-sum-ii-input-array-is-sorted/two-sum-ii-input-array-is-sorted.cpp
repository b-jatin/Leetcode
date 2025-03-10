class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0,len=numbers.size();
        int j=len-1;
        vector<int> temp={};
        
        while(i<j){
            if(numbers[i]+numbers[j]==target){
                temp.push_back(i+1);
                temp.push_back(j+1);
                break;
            }
          /*  else if(numbers[j]>target){
                j--;
               // continue;
            }*/
            if(numbers[i]+numbers[j]<target){
                i++;
            }
            else if(numbers[i]+numbers[j]>target){
                j--;
            }
            
        }
        return temp;

    }
};