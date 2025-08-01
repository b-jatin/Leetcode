class Solution {
public:
    bool isPalindrome(string s){
        int n=s.size();
        int i=0,j=n-1;
        while(i<j){
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(int start,vector<vector<string>>& answer, vector<string>& subst, string s){
        if(start== s.length()){
        answer.push_back(subst);
        return;
        }
        for(int i=start;i<s.length();i++){
            if(isPalindrome(s.substr(start,i-start+1))){
                subst.push_back(s.substr(start,i-start+1));
                solve(i+1,answer,subst,s);
                subst.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> answer;
        vector<string> subst;
        solve(0,answer, subst, s);
        return answer;
    }
};