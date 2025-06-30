class Solution {
public:
    int find(int x, vector<int>& parent) {
        if (x != parent[x]) {
            parent[x] = find(parent[x], parent);  // Path compression
        }
        return parent[x];
    }

    bool unionSet(int x, int y, vector<int>& parent, vector<int>& rank) {
        int parent_x = find(x, parent);
        int parent_y = find(y, parent);

        if (parent_x == parent_y) return false;

        // Union by rank
        if (rank[parent_x] < rank[parent_y]) {
            parent[parent_x] = parent_y;
        } else if (rank[parent_x] > rank[parent_y]) {
            parent[parent_y] = parent_x;
        } else {
            parent[parent_y] = parent_x;
            rank[parent_x]++;
        }
        return true;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> parent(n);
        vector<int> rank(n, 0);

        // Initialize parent of each node to itself
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }

        // Union all connected nodes
        for (auto& edge : edges) {
            unionSet(edge[0], edge[1], parent, rank);
        }

        // Check if source and destination are connected
        return find(source, parent) == find(destination, parent);
    }
};
