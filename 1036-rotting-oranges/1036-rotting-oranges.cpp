class Solution {
public:
    void bfs(int m, int n, vector<vector<int>> &grid, vector<vector<bool>> &vis, queue<pair<pair<int, int>, int>> &q, int &rotted, int &time, int fresh) {
        int r[] = {-1, 0, 1, 0};
        int c[] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto p = q.front(); q.pop();
            int x = p.first.first;
            int y = p.first.second;
            int t = p.second;

            time = max(time, t);

            for (int k = 0; k < 4; k++) {
                int nx = x + r[k];
                int ny = y + c[k];

                if (nx >= 0 && ny >= 0 && nx < m && ny < n &&
                    grid[nx][ny] == 1 && !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    rotted++;
                    q.push({{nx, ny}, t + 1});
                }
            }
        }
    }

    void prepare(int m, int n, vector<vector<int>> &grid, vector<vector<bool>> &vis, queue<pair<pair<int, int>, int>> &q, int &fresh) {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = true;
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
    }

    int orangesRotting(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));
        queue<pair<pair<int, int>, int>> q;

        int fresh = 0;
        int rotted = 0;
        int time = 0;

        prepare(m, n, grid, vis, q, fresh);
        bfs(m, n, grid, vis, q, rotted, time, fresh);

        return (rotted == fresh) ? time : -1;
    }
};
