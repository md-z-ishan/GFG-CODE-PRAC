class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        // Build Graph
        for (int i = 0; i < prerequisites.size(); i++) {
            int course = prerequisites[i][0];
            int pre = prerequisites[i][1];

            adj[pre].push_back(course);
            indegree[course]++;
        }

        queue<int> q;

        // Push all nodes having indegree 0
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            count++;

            for (int it : adj[node]) {

                indegree[it]--;

                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        return count == n;
    }
};