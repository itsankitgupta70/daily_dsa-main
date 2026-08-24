class Solution {
public:
    typedef pair<int, string> p;

    class comp {
    public:
        bool operator()(const p& a, const p& b) {
            if (a.first != b.first)
                return a.first > b.first;

            return a.second < b.second;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;

        for (auto& word : words)
            mp[word]++;

        priority_queue<p, vector<p>, comp> pq;

        for (auto& it : mp) {
            if (pq.size() < k) {
                pq.push({it.second, it.first});
            }
            else if (pq.top().first < it.second ||
                     (pq.top().first == it.second &&
                      pq.top().second > it.first)) {
                pq.pop();
                pq.push({it.second, it.first});
            }
        }

        vector<string> res;

        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};