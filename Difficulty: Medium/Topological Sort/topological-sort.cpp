class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> in_degree(V,0);
        vector<int> adj[V];
        queue<int> q;
        vector<int> vis(V,0);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }
        
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                in_degree[it]++;
            }
        }
        
        for(int i =0;i<V;i++){
            if(in_degree[i]==0){
                q.push(i);
                vis[i]=1;
            }
        }
        vector<int> ans;
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it : adj[node]){
                in_degree[it]--;
                if(in_degree[it]==0){
                    q.push(it);
                }
            }
        }
        return ans;
    }
};