class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;

        for (char ch : s) {
            mp[ch]++;
        }

        priority_queue<pair<int, char>> pq;

        for (auto& [ch, freq] : mp) {
            pq.push({freq, ch});
        }

        string res = "";

        while (!pq.empty()) {
            auto [freq, ch] = pq.top();
            pq.pop();
            if (!res.empty() && res.back() == ch) {
                if (pq.empty()) {
                    return "";
                }

                auto [freq1, ch1] = pq.top();
                pq.pop();

                res.push_back(ch1);
                freq1--;

                if (freq1 > 0) {
                    pq.push({freq1, ch1});
                }

                // Put original character back
                pq.push({freq, ch});

            } else {
                res.push_back(ch);
                freq--;

                if (freq > 0) {
                    pq.push({freq, ch});
                }
            }
        }

        return res;
    }
};