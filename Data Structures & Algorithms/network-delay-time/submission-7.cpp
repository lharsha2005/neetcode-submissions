class Solution {
public:
    map<vector<int>,int> htime;
    unordered_map<int,vector<int>> hmap;

    void dfs(int node, int count, vector<int>& dis) {
        if (count >= dis[node]) return;

        dis[node] = count;

        for (int nig : hmap[node]) {
            int temp = count + htime[{node, nig}];
            dfs(nig, temp, dis);
        }
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        for (vector<int>& edge : times) {
            hmap[edge[0]].push_back(edge[1]);
            htime[{edge[0], edge[1]}] = edge[2];
        }

        vector<int> dis(n + 1, INT_MAX);

        dfs(k, 0, dis);

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dis[i] == INT_MAX) return -1;
            ans = max(ans, dis[i]);
        }

        return ans;
    }
};