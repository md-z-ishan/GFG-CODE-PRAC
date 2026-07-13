class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<pair<int,int>>adj[V];
        vector<int> indegree(V,0);
        //graph banayenge
        for(int i=0;i<E;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            
            adj[u].push_back({v,wt});
            indegree[v]++;
        }
        //ab bfs topologi lagayenge
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
            vector<int>topo;
            while(!q.empty()){
                int node=q.front();
                q.pop();
                topo.push_back(node);
                for(auto it : adj[node]){
                    int v=it.first;
                    indegree[v]--;
                    
                    if(indegree[v]==0)
                    q.push(v);
                    
                }
            }
            //distance array 
            vector<int> dist(V, INT_MAX);
            dist[0] = 0;
            
            //relax krenge edges 
            for(auto node : topo) {

            if(dist[node] != INT_MAX) {

                for(auto it : adj[node]) {

                    int v = it.first;
                    int wt = it.second;

                    if(dist[node] + wt < dist[v]) {
                        dist[v] = dist[node] + wt;
                    }
                }
            }
        }
        for(int i=0;i<V;i++){
            if(dist[i]==INT_MAX){
                dist[i]=-1;
            }
        }
        return dist;
        }
    
};
