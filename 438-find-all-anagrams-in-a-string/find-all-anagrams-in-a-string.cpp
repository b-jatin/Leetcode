class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        unordered_map<char,int> um;
        for(auto i:p){
            um[i]++;
        }
        int start=0,end=0,k=p.length(),count=um.size();
        while(end<s.length()){
            if(um.find(s[end])!=um.end()){
                um[s[end]]--;
                if(um[s[end]]==0){
                    count--;
                }
            }
            if(end-start+1<k){
                end++;
            }
            else if(end-start+1==k){
                if(count==0){
                    ans.push_back(start);
                }
                if(um.find(s[start])!=um.end()){
                    um[s[start]]++;
                    if(um[s[start]]==1)
                        count++;
                }
                start++;
                end++;
            }

        }
        return ans;
    }
};