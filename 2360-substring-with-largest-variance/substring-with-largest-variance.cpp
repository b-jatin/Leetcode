class Solution {
public:
    int largestVariance(string s) { //kadane algo assume(c1>=c2) 
        vector<int> arr(26);
        int maxi=0;
        for(auto x:s){
            arr[x-'a']++;
        }
        for(int i='a';i<='z';i++){
            for(int j='a';j<='z';j++){
                if(i==j|| arr[i-'a']==0 || arr[j-'a']==0)
                    continue;
                for(int k=1;k<=2;k++){
                    int c1=0,c2=0;
                    for(auto x:s){
                        if(x==i)
                            c1++;
                        if(x==j)
                            c2++;
                        if(c1<c2)
                        {
                            c1=0;
                            c2=0;
                        }
                        if(c1>0 && c2>0){
                            maxi=max(maxi,c1-c2);
                        }
                    }
                    reverse(s.begin(),s.end());
                    
                }
            }
        }
        return maxi;
    }
};