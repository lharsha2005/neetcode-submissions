class Solution {
public:
    string minWindow(string s, string t) {

        if (t.size() == 1) {
            for (char ch : s) {
                if (ch == t[0])
                    return t;
            }
            return "";
        }

        if (s.size() < t.size())
            return "";

        unordered_map<char, int> hash;

        int count = 0;
        int ans = INT_MAX;
        int ml = -1, mr = -1;

        for (char ch : t) {
            hash[ch]++;
            count++;
        }

        int l = 0;
        int temp = 0;

        for (int r = 0; r < s.size(); r++) {

            if (hash.find(s[r]) != hash.end()) {

                if (hash[s[r]] > 0)
                    temp++;

                hash[s[r]]--;
            }

            if (temp == count) {

                // Remove unnecessary characters
                while (hash.find(s[l]) == hash.end() ||
                       hash[s[l]] < 0) {

                    if (hash.find(s[l]) != hash.end())
                        hash[s[l]]++;

                    l++;
                }

                // Update answer
                if (r - l + 1 < ans) {
                    ans = r - l + 1;
                    ml = l;
                    mr = r;
                }

                // Remove one required character
                hash[s[l]]++;
                temp--;
                l++;
            }
        }

        if (ml == -1)
            return "";

        return s.substr(ml, mr - ml + 1);
    }
};