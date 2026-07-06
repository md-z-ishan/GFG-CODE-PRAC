class Solution {
public:

    void solve(int node, vector<vector<int>>& adj,
               vector<bool>& vis, vector<int>& ans) {

        vis[node] = true;
        ans.push_back(node);

        for (int neighbour : adj[node]) {

            if (!vis[neighbour]) {
                solve(neighbour, adj, vis, ans);
            }

        }
    }

    vector<int> dfs(vector<vector<int>>& adj) {

        int V = adj.size();

        vector<bool> vis(V, false);
        vector<int> ans;

        solve(0, adj, vis, ans);

        return ans;
    }
};