class Solution {
    void dfs(int u, vector<int> adj[], vector<int>& vis) {
        vis[u] = 1;

        for(int v : adj[u]) {
            if(!vis[v])
                dfs(v, adj, vis);
        }
    }

public:
    bool isCircle(vector<string> &arr) {

        vector<int> in(26, 0), out(26, 0);
        vector<int> adj[26];

        for(string &s : arr) {
            int u = s.front() - 'a';
            int v = s.back() - 'a';

            out[u]++;
            in[v]++;
            adj[u].push_back(v);
        }

        for(int i = 0; i < 26; i++) {
            if(in[i] != out[i])
                return false;
        }

        int start = -1;
        for(int i = 0; i < 26; i++) {
            if(out[i] > 0) {
                start = i;
                break;
            }
        }

        vector<int> vis(26, 0);
        dfs(start, adj, vis);

        for(int i = 0; i < 26; i++) {
            if((in[i] > 0 || out[i] > 0) && !vis[i])
                return false;
        }

        return true;
    }
};