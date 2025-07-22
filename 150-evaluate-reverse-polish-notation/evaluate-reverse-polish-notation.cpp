class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int first=0,second=0;
        int n=tokens.size();
        for(auto i:tokens){
            if(i=="+"){
                second=st.top();st.pop();
                first=st.top();st.pop();
                st.push(first+second);
            }
            else if(i=="-"){
                second=st.top();st.pop();
                first=st.top();st.pop();
                st.push(first-second);
            }
            else if(i=="*"){
                second=st.top();st.pop();
                first=st.top();st.pop();
                st.push(first*second);
            }
            else if(i=="/"){
                second=st.top();st.pop();
                first=st.top();st.pop();
                st.push(first/second);
            }
            else{
                st.push(stoi(i));
            }
        }
        return st.top();
    }
};