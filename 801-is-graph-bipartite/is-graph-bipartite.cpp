class Solution {
public:
    bool bfs(vector<vector<int>>& graph, int v, int start,vector<int>& color ){
        //striver solution
        queue<int> q;
        q.push(start);
        color[start]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto x: graph[node]){
                if(color[x]==-1){
                    q.push(x);
                    color[x]=!color[node];
                }
                else if(color[x]==color[node]){
                    return false;
                }
            }
        }
        return true;
    }


    bool isBipartite(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<int> color(v);
        for(int i=0;i<v;i++)
            color[i]=-1;

        for(int i=0;i<v;i++)
        if(color[i]==-1){
           if( !bfs(graph,v,i,color))
                return false;
        }
        return true;
    }
};