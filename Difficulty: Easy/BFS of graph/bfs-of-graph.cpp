class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int n=adj.size();
        vector<bool> vis(n,false);
        vector<int> ans;
        
        int src=0;
        vis[src]=true;
        queue<int> q;
        q.push(src);
        
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            ans.push_back(curr);
            
            for(auto x:adj[curr]){
                if(vis[x]==false){
                    
                
                vis[x]=true;
                q.push(x);
                }
            }
        }
        return ans;
    }
};