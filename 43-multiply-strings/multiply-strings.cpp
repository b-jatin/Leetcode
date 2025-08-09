class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0")
        return "0";
        int s1=num1.size();
        int s2=num2.size();
        vector<int> ans(s1+s2,0);
        for(int i=s1-1;i>=0;i--){
            for(int j=s2-1;j>=0;j--){
                ans[i+j+1]+=(num1[i]-'0')*(num2[j]-'0');
                ans[i+j]+=ans[i+j+1]/10;
                ans[i+j+1]%=10;
            }
        }
        int x=0;
        while(x<ans.size() && ans[x]==0)++x;
        string res="";
        for(int i=x;i<ans.size();i++){
            res.push_back(ans[i]+'0');
        }
        return res;
    }
};