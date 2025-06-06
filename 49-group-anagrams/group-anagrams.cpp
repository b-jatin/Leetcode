class Solution {
public:

    string string_sort(string m){
        sort(m.begin(),m.end());
        return m;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> temp;
        vector<vector<string>> ans;
        for(auto i: strs){
            string t=i;
            sort(t.begin(),t.end());
            temp[t].push_back(i);
        }
        for(auto i: temp){
            ans.push_back(i.second);
        }
        return ans;
        

        /* for( auto i : strs){
            string x=i;
            sort(x.begin(),x.end());
            temp[x].push_back(i);
        }
        vector<vector<string>> temp2;
        for(auto i=temp.begin();i!= temp.end();i++){
            temp2.push_back(i->second);
        }
        return temp2; */
    }
};