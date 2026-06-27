class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;
        for (auto& x : nums) {
            freq[x]++;
        }

        int ans = 1;

        if (freq.count(1)) {
            ans = max(ans, freq[1] % 2 ? freq[1] : freq[1] - 1);
        }

        for (auto& [start, _] : freq) {
            if (start == 1) {
                continue;
            }
            long long curr = start;
            int len = 0;

            while (true) {
                auto it = freq.find(curr);

                if (it != freq.end() && it->second >= 2) {
                    len += 2;
                    curr *= curr;
                } else if (it != freq.end() && it->second >= 1) {
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