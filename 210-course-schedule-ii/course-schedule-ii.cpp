class Solution {
public:

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>  indegree(numCourses,0);
        vector<vector<int>> adj(numCourses);
        for(auto i: prerequisites)
            adj[i[1]].push_back(i[0]);
        for(auto x: adj){
            for(auto i:x){
                indegree[i]++;
            }
        }
        vector<int> ans;
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)
              q.push(i);
            
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto i:adj[node]){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                    }
            }
        }
        if(numCourses==ans.size())
        return ans;
        return {};

    }
};