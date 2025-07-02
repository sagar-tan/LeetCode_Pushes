#define MOD 1000000007

class Solution {
public:
    void buildAdjacency(int n, vector<vector<int>>& roads, vector<vector<pair<int, int>>>& adj) {
        for (int i = 0; i < roads.size(); ++i) {
            int u = roads[i][0];
            int v = roads[i][1];
            int t = roads[i][2];
            adj[u].push_back(make_pair(v, t));
            adj[v].push_back(make_pair(u, t));
        }
    }

    int dijkstraPaths(int n, vector<vector<pair<int, int>>>& adj) {
        vector<long long> dist(n, LLONG_MAX);  // upgraded to long long
        vector<int> ways(n, 0);

        // Min-heap: {distance, node}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.push(make_pair(0, 0));

        while (!pq.empty()) {
            pair<long long, int> top = pq.top(); pq.pop();
            long long d = top.first;
            int u = top.second;

            if (d > dist[u]) continue;

            for (int i = 0; i < adj[u].size(); ++i) {
                int v = adj[u][i].first;
                int wt = adj[u][i].second;
                long long newDist = d + wt;

                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    ways[v] = ways[u];
                    pq.push(make_pair(newDist, v));
                } else if (newDist == dist[v]) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }
        return ways[n - 1];
    }

    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        buildAdjacency(n, roads, adj);
        return dijkstraPaths(n, adj);
    }
};
