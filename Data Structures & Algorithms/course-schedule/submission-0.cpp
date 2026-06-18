class Solution {
public:
    unordered_map<int, vector<int>> graph;

    bool dfs(int node, vector<int>& state) {
        if(state[node] == 1) return false; // cycle
        if(state[node] == 2) return true;  // already processed

        state[node] = 1;

        for(int nei : graph[node]) {
            if(!dfs(nei, state))
                return false;
        }

        state[node] = 2;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(auto& p : prerequisites) {
            graph[p[0]].push_back(p[1]);
        }

        vector<int> state(numCourses, 0);

        for(int i = 0; i < numCourses; i++) {
            if(!dfs(i, state))
                return false;
        }

        return true;
    }
};