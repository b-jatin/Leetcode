class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> pos;
        for(int i=0;i<position.size();i++){
            pos.push_back({position[i],speed[i]});
        }
        sort(pos.begin(),pos.end(),greater<pair<int,int>>());
        stack<float> st;
        for(int i=0;i<speed.size();i++){
            int spd=pos[i].second;
            int posi=pos[i].first;
            double time=(double)(target-posi)/spd;
            if(st.empty() || time>st.top())
            {
                st.push(time);
            }
        }
        return st.size();
    }
};