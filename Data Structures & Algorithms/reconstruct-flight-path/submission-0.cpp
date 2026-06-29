class Solution {
public:
    unordered_map<string, vector<string>> hash;
    unordered_map<string, vector<bool>> used;
    vector<string> itinerary;
    int totalTickets;

    bool dfs(string from) {
        itinerary.push_back(from);

        if (itinerary.size() == totalTickets + 1)
            return true;

        for (int i = 0; i < hash[from].size(); i++) {
            if (used[from][i]) continue;

            used[from][i] = true;

            if (dfs(hash[from][i]))
                return true;

            used[from][i] = false;
        }

        itinerary.pop_back();
        return false;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        totalTickets = tickets.size();

        for (auto &ticket : tickets)
            hash[ticket[0]].push_back(ticket[1]);

        for (auto &it : hash) {
            sort(it.second.begin(), it.second.end());
            used[it.first] = vector<bool>(it.second.size(), false);
        }

        dfs("JFK");

        return itinerary;
    }
};