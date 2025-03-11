class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> temp;
        int start=0,end=0, len=fruits.size(),maxf=INT_MIN;
        while(end<len){
            if(temp.count(fruits[end])==0)
            temp.insert({fruits[end],0});
            temp[fruits[end]]++;
            while(temp.size()>2){
                temp[fruits[start]]--;
                if(temp[fruits[start]]==0)
                    temp.erase(fruits[start]);
                start++;
            }
            if(temp.size()<=2){
                maxf=max(maxf,end-start+1);
            }

            end ++;
        }
        return maxf;
    }
};