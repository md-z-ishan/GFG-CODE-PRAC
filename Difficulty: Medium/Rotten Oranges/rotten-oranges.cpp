class Solution {
public:
    int orangesRot(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;

        // Store all rotten oranges and count fresh oranges
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (mat[i][j] == 2) {
                    q.push({i, j});
                }

                else if (mat[i][j] == 1) {
                    fresh++;
                }
            }
        }

        if (fresh == 0)
            return 0;

        int time = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {

            int size = q.size();
            int rotten = 0;

            while (size--) {

                pair<int, int> curr = q.front();
                q.pop();

                int row = curr.first;
                int col = curr.second;

                for (int i = 0; i < 4; i++) {

                    int nr = row + dr[i];
                    int nc = col + dc[i];

                    if (nr >= 0 && nr < m &&
                        nc >= 0 && nc < n &&
                        mat[nr][nc] == 1) {

                        mat[nr][nc] = 2;
                        q.push({nr, nc});

                        fresh--;
                        rotten++;
                    }
                }
            }

            if (rotten > 0)
                time++;
        }

        if (fresh > 0)
            return -1;

        return time;
    }
};