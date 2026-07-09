class Solution {
  public:
    bool dfs(vector<int> adj[],int src,int col ,vector<int> &color){
        color[src]=col;
        for(auto it : adj[src]){
            if(color[it]==-1){
                if(dfs(adj,it,!col,color)==false){
                    return false;
                }
            }
            else if(color[it]==col){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        vector<int> adj[V+1];
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v= edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> color(V+1,-1);
        int col=0;
        int src=0;
        bool ans = dfs(adj,src,col,color);
        return ans;
    }
};