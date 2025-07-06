class Solution {
public:
    string longestPalindrome(string s) {
        int len=0;
        string res="";
        int left=0,right=0;
        for(int i=0;i<s.length();i++){
            left=i;
            right=i;
            while(left>=0 && right<s.length() && s[left]==s[right]){
                if(len<right-left+1)
                {
                    res=s.substr(left,right-left+1);
                    len=right-left+1;
                }
                left--;
                right++;
            }
            left=i;
            right=i+1;
            while(left>=0 && right<s.length() && s[left]==s[right]){
                if(len<right-left+1)
                {
                    res=s.substr(left,right-left+1);
                    len=right-left+1;
                }
                left--;
                right++;
            }
        }
        return res;
    }
};