class Solution {
public:
    bool isSubsequence(string s, string t) {
        int len=t.size();
        int len2=s.size();
       int j=0;
        for(int i=0;i<len && j<len2;i++){
            if(t[i]==s[j]){
                j++;
            }
        }
        if(j==len2)
        return true;
        return false;
    }
};