class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> reverse(n);
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++)
        for(auto x: graph[i])
        {
            reverse[x].push_back(i);
            indegree[i]++;
        }
        queue<int> q;
        
        for(int i=0;i<n;i++){
            if(indegree[i]==0)
                q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int node=q.front();
            ans.push_back(node);
            q.pop();
            for(auto i: reverse[node]){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};