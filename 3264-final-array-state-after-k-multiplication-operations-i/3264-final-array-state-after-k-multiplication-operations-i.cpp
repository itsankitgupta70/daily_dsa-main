class Solution {
public:
    typedef pair<int, int> p;
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<p, vector<p>, greater<p>> pq;
        int idx = 0;
        for (int& num : nums) {
            pq.push({num, idx});
            idx++;
        }
        for (int i = 0; i < k; i++) {
            int x = pq.top().first;
            int y = pq.top().second;
            pq.pop();
            x *= multiplier;
            pq.push({x, y});
        }
        vector<int> ans(nums.size());
        while (!pq.empty()) {
            ans[pq.top().second] = pq.top().first;
            pq.pop();
        }
        return ans;
    }
};