class Solution {
public:
    unordered_map<int, vector<int>> hash;

    bool dfs(int node, int parent, vector<int>& visited) {
        visited[node] = 1;

        for (int nei : hash[node]) {
            if (nei == parent) continue;

            if (visited[nei]) return false; // cycle found

            if (!dfs(nei, node, visited))
                return false;
        }

        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;

        for (auto& e : edges) {
            hash[e[0]].push_back(e[1]);
            hash[e[1]].push_back(e[0]);
        }

        vector<int> visited(n, 0);

        if (!dfs(0, -1, visited))
            return false;

        for (int i = 0; i < n; i++) {
            if (!visited[i])
                return false; // disconnected
        }

        return true;
    }
};