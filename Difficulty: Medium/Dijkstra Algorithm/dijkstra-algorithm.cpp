class Solution {
	public:
	vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
		// Code here
		vector<vector<pair<int,int>>>adj(V);
		for (auto &e:edges) {
			int u = e[0];
			int v = e[1];
			int wt = e[2];
			adj[u].push_back({v, wt});
			adj[v].push_back({u, wt}); // Undirected ke liye
		}
		vector<int> dist(V, INT_MAX);
		priority_queue<pair<int, int>, vector<pair<int, int>>,
		greater<pair<int, int>> > pq;
		
		dist[src] = 0;
		pq.push({0, src});
		
		while (!pq.empty()) {
			auto[dis, node] = pq.top();
			pq.pop();
			
			if (dis<dist[node])continue;
			
			for (auto &it:adj[node]) {
				int wt = it.second;
				int v = it.first;
				if (dis + wt<dist[v]) {
					dist[v] = dis + wt;
					pq.push({dist[v], v});
				}
			}
		}
		return dist;
	}
};
