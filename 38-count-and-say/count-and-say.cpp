class Solution {
public:
    string countAndSay(int n) {
        string res="1";
        for(int i=1;i<n;i++){
            res=RES(res);
        }
        return res;
    }
    string RES(string s){
        int count=1;
        string res="";
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]){
                count++;
            }
            else{
                res+=to_string(count)+s[i-1];
                count=1;
            }
        }
        return res+=to_string(count)+s.back();
    }
};