class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> um;
    string search(vector<pair<int,string>>& temp,int time){
        int l=0, r=temp.size()-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(temp[mid].first<time){
                l=mid+1;
            }
            else if(temp[mid].first>time){
                r=mid-1;
            }
            else{
                return temp[mid].second;
            }
        }
        return r>=0?temp[r].second:"";
    }
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        um[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(um.find(key)==um.end())
        return "";
        return search(um[key],timestamp);
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */