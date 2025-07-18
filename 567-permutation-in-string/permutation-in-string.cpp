class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size())
        return false;
        vector<int> s1count(26),s2count(26);
        int i;
        for( i=0;i<s1.size();i++){
            s1count[s1[i]-'a']++;
            s2count[s2[i]-'a']++;
        }
        if(s1count==s2count)return true;
        int start=0,end=i;
        while(end<s2.size()){
            --s2count[s2[start]-'a'];
            ++s2count[s2[end]-'a'];
            if(s1count==s2count)
            return true;
            end++;
            start++;
        }
        return false;

    }
};