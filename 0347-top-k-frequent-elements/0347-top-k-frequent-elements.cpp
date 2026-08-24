class Solution {
public:
    typedef pair<int, int> P;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // sare elements ko map kar do unke frequncy ke hisab se
        unordered_map<int, int> mp;
        for (auto& num : nums) {
            mp[num]++;
        }
        // ab ek min heap banao jise frequncy ke basis pe sort karo
        priority_queue<P, vector<P>, greater<P>> pq;
        // itrate full map
        for (auto& it : mp) {
            int val = it.first;
            int freq = it.second;
            pq.push({freq, val});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        // result vector bana lo
        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};