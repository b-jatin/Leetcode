class Solution {
public:
    bool isValid(string s) {
        stack<char> temp;
        int len=s.size();
        for(int i=0;i<len;i++){
            if(s[i]=='('||s[i]=='{'||s[i]=='[')
                 temp.push(s[i]);
                else{
                    if(temp.empty())
                    return false;
                    if(s[i]==')' && temp.top()!='(')
                        return false;
                    if(s[i]=='}' && temp.top()!='{')
                        return false;
                    if(s[i]==']' && temp.top()!='[')
                        return false;
                    temp.pop();
                }
        }
        if(temp.empty())
        return true;
        return false;
    }
};