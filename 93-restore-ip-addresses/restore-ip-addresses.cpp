class Solution {
public:
    bool isValid(string s){
        int l=s.size();
        if(l>3||l==0)
        return false;
        if(l>1 && s[0]=='0')
        return false;
        if(l&& stoi(s)>255)
        return false;

        return true;
    }
    void solve(vector<string>& ans,int index,int dots, string temp, string s){
        if(dots==3){
            if(isValid(s.substr(index))){
                ans.push_back(temp+s.substr(index));
                
            }
            return;
        }
        for(int j=index;j<s.size();j++){
            if(isValid(s.substr(index,j-index+1))){
                temp.push_back(s[j]);
                temp.push_back('.');
                solve(ans,j+1,dots+1,temp,s);
                temp.pop_back();
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        if(s.size()<4)
        return ans;
        solve(ans,0,0,"",s);
        return ans;
    }
};