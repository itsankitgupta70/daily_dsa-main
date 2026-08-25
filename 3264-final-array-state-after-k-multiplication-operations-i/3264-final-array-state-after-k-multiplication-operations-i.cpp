class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        using P = pair<int, int>;

        priority_queue<P, vector<P>, greater<P>> pq;

        for (int i = 0; i < nums.size(); i++)
            pq.push({nums[i], i});

        while (k--) {
            auto [value, index] = pq.top();
            pq.pop();

            pq.push({value * multiplier, index});
        }

        while (!pq.empty()) {
            auto [value, index] = pq.top();
            pq.pop();

            nums[index] = value;
        }

        return nums;
    }
};