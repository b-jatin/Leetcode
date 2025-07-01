class Solution {
public:
    bool dfs(int start,vector<vector<int>>& adj,vector<int> & visited, vector<int>& path,int n){
        visited[start]=1;
        path[start]=1;
        for(auto x: adj[start]){
            if(!visited[x]){
               if( dfs(x,adj,visited,path,n)==false)
                    return false;
            }
            else if(path[x])
                return false;
        }
        path[start]=0;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto i: prerequisites){
            adj[i[1]].push_back(i[0]);
        }
        vector<int> visited(numCourses,0), path(numCourses,0);
        for(int i=0;i<numCourses;i++){
                if(dfs(i,adj,visited,path,numCourses)==false)
                    return false;
        }
        return true;
    }
};