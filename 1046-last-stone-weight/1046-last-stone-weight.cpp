class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (auto& stone : stones) {
            pq.push(stone);
        }
        int ans = 0;
        while (!pq.empty()) {
            int y = pq.top();
            ans = y;
            pq.pop();
            if (pq.size() == 0) {
                return ans;
            }
            int x = pq.top();
            ans -= x;
            pq.pop();
            pq.push(ans);
        }
        return 0;
    }
};