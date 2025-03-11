class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int end=0,start=0,len=s.size(), maxl=INT_MIN;
        unordered_set<char> temp;
        if(len==0)
        return 0;
        while(end<len){
            if(temp.find(s[end])==temp.end()){
                temp.insert(s[end]);
                end++;
            }
            else{
                temp.erase(s[start]);
                start++;
            }

            maxl= max (maxl,(int)temp.size());
        }
        return maxl;
    }
};