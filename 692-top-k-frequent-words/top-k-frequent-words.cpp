struct cmp {
    bool operator()(auto& a, auto& b) {
        if (a.first == b.first)
            return a.second < b.second;  // reverse lexicographic for ties
        return a.first > b.first;        // smaller freq at top
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> um;
        vector<string> ans;
        for(auto i:words){
            um[i]++;
        }
        priority_queue<pair<int,string>, vector<pair<int,string>>,cmp> pq;
        for(auto  i=um.begin();i!=um.end();i++){
            pq.push({i->second,i->first});
            if(pq.size()>k) 
                pq.pop();
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};