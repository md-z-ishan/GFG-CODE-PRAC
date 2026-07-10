class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>> &prerequisites) {

        vector<int> adj[n];

        // Build Graph
        for (int i = 0; i < prerequisites.size(); i++) {

            int course = prerequisites[i][0];
            int pre = prerequisites[i][1];

            adj[pre].push_back(course);
        }

        // Calculate Indegree
        vector<int> indegree(n, 0);

        for (int i = 0; i < n; i++) {

            for (auto it : adj[i]) {

                indegree[it]++;
            }
        }

        // Push all nodes having indegree 0
        queue<int> q;

        for (int i = 0; i < n; i++) {

            if (indegree[i] == 0) {

                q.push(i);
            }
        }

        vector<int> ans;

        // Kahn's Algorithm
        while (!q.empty()) {

            int node = q.front();
            q.pop();

            ans.push_back(node);

            for (auto it : adj[node]) {

                indegree[it]--;

                if (indegree[it] == 0) {

                    q.push(it);
                }
            }
        }

        // If cycle exists
        if (ans.size() != n) {

            return {};
        }

        return ans;
    }
};