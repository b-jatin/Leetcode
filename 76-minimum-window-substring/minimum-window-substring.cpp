class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map(256,0);
        for (char c : t) {
            map[c]++;
        }

        int counter = t.size(), begin = 0, end = 0, d = INT_MAX, head = 0;
        while (end < s.size()){
            if (map[s[end++]]-- > 0) {
                counter--;
            }
            while (counter == 0) {
                if (end - begin < d) {
                    head = begin;
                    d = end - head;
                }
                if (map[s[begin++]]++ == 0) {
                    counter++;
                }
            }  
        }
        return d == INT_MAX ? "" : s.substr(head, d);
        
        
        /* int len1=s.size(),len2=t.size(), start=0,end=0,m=INT_MAX, count=0, startIndex=-1;
        vector<int> hash(256,0);
        string ans="";
        if(len1<len2)
        return ans;
        for(auto i:t){
            hash[i]++;
        }
        while(end<len1){
            if(hash[s[end]]>0){
                count++;
                hash[s[end]]--;
            }
            while(count==len2){
                    if((end-start)<m)
                    { m= end-start;
                       startIndex=start;
                    }
                   
                    if(hash[s[start++]]++==0){
                    count--;
                    }
                
            }
            end++;
        }
        return m==INT_MAX?"":s.substr(startIndex,m); */
            



            
        
    }
};