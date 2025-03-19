class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxl=INT_MIN,maxf=0,end=0,start=0,n=s.size();
        int arr[26]={0};

        while(end<n){
            arr[s[end]-'A']++;
            maxf=max(maxf,arr[s[end]-'A']);
            if((end-start+1)-maxf>k){
                arr[s[start]-'A']--;
                
                start++;
            }
            if((end-start+1)-maxf<=k){
                //maxf=max(arr[s[end]-'A'],arr[s[end]-'A']-k);
                maxl=max(maxl,(end-start+1));
            }
            end++;
        }
        return maxl;
    }
};