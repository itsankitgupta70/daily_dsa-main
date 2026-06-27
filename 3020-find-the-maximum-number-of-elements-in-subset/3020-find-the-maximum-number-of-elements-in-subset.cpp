class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> count;
        for (auto& x : nums) {
            count[x]++;
        }

        int ans = 1;

        if (count.count(1)) {
            ans = max(ans, count[1] % 2 ? count[1] : count[1] - 1);
        }

        for (auto& [start, _] : count) {
            if (start == 1) {
                continue;
            }
            long long curr = start;
            int len = 0;

            while (true) {
                auto it = count.find(curr);

                if (it != count.end() && it->second >= 2) {
                    len += 2;
                    curr *= curr;
                } else if (it != count.end() && it->second >= 1) {
                    len++;
                    break;
                } else {
                    len--;
                    break;
                }
            }
            ans = max(ans, len);
        }

        return ans;
    }
};