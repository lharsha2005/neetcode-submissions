class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        priority_queue<int> pq;
        queue<pair<int, int>> dq;

        for (int i = 0; i < tasks.size(); i++) {
            count[tasks[i] - 'A']++;
        }

        for (int i = 0; i < count.size(); i++) {
            if (count[i] > 0) {
                pq.push(count[i]);
            }
        }

        int time = 0;

        while (!pq.empty() || !dq.empty()) {
            time++;

            // Check if a task has completed its cooldown
            if (!dq.empty() && dq.front().second == time) {
                auto tp = dq.front();
                dq.pop();

                pq.push(tp.first);
            }

            // Execute highest-frequency available task
            if (!pq.empty()) {
                int tp = pq.top();
                pq.pop();

                tp--;

                if (tp > 0) {
                    dq.push({tp, time + n + 1});
                }
            }
        }

        return time;
    }
};