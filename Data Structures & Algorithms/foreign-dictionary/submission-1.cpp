class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, vector<char>> graph;
        unordered_map<char, int> indegree;

        // Initialize all characters
        for (auto &word : words) {
            for (char c : word) {
                graph[c];
                indegree[c] = 0;
            }
        }

        // Build graph
        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i];
            string w2 = words[i + 1];

            // Invalid prefix case
            if (w1.size() > w2.size() &&
                w1.substr(0, w2.size()) == w2)
                return "";

            int len = min(w1.size(), w2.size());

            for (int j = 0; j < len; j++) {
                if (w1[j] != w2[j]) {
                    graph[w1[j]].push_back(w2[j]);
                    indegree[w2[j]]++;
                    break;          // only first difference matters
                }
            }
        }

        // Topological Sort
        queue<char> q;

        for (auto &it : indegree) {
            if (it.second == 0)
                q.push(it.first);
        }

        string ans;

        while (!q.empty()) {
            char u = q.front();
            q.pop();

            ans += u;

            for (char v : graph[u]) {
                indegree[v]--;
                if (indegree[v] == 0)
                    q.push(v);
            }
        }

        // Cycle detected
        if (ans.size() != indegree.size())
            return "";

        return ans;
    }
};