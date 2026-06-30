/*
struct Node {
    int data;
    Node *left;
    Node *right;
};
*/

class Solution {
public:
    unordered_map<int, vector<int>> adj;

    // Tree -> Undirected Graph
    void buildGraph(Node* root) {
        if (!root)
            return;

        if (root->left) {
            adj[root->data].push_back(root->left->data);
            adj[root->left->data].push_back(root->data);
            buildGraph(root->left);
        }

        if (root->right) {
            adj[root->data].push_back(root->right->data);
            adj[root->right->data].push_back(root->data);
            buildGraph(root->right);
        }
    }

    int minTime(Node* root, int target) {

        buildGraph(root);

        queue<int> q;
        unordered_set<int> vis;

        q.push(target);
        vis.insert(target);

        int time = -1;

        while (!q.empty()) {

            int sz = q.size();
            time++;

            while (sz--) {

                int node = q.front();
                q.pop();

                for (int nbr : adj[node]) {

                    if (!vis.count(nbr)) {
                        vis.insert(nbr);
                        q.push(nbr);
                    }
                }
            }
        }

        return time;
    }
};