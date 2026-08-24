class Solution {
public:
    typedef pair<int, string> P;

    struct comp {
        bool operator()(const P& a, const P& b) {
            if (a.first != b.first)
                return a.first > b.first;

            return a.second < b.second;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;

        for (string& word : words)
            freq[word]++;

        priority_queue<P, vector<P>, comp> pq;

        for (auto& [word, count] : freq) {
            pq.push({count, word});

            if (pq.size() > k)
                pq.pop();
        }

        vector<string> ans;

        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};