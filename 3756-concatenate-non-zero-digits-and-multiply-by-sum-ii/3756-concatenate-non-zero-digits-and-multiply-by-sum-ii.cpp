class Solution {
public:
    static const int MOD = 1e9 + 7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> cnt(n + 1, 0);      // non zero ka count
        vector<long long> preNum(1, 0); // concatinate number
        vector<int> preSum(1, 0);       // pre sum

        for (int i = 0; i < n; i++) {
            cnt[i + 1] = cnt[i];
            if (s[i] != '0') {
                int digit = s[i] - '0';
                cnt[i + 1]++;
                preNum.push_back((preNum.back() * 10 + digit) % MOD);
                preSum.push_back(preSum.back() + digit);
            }
        }

        //  power of 10 har place ke liye bhi calculate kar lo
        int m = preNum.size();
        vector<long long> powOf10(m, 1);
        for (int i = 1; i < m; i++) {
            powOf10[i] = ((powOf10[i - 1] * 10) % MOD);
        }

        vector<int> ans;
        for (auto& q : queries) {
            int l = q[0];
            int r = q[1];

            int left = cnt[l];  // left ke sare zero ka count
            int right = cnt[r+1]; // right me last kaha tak dekhna hai

            int len = right - left;
            long long x = (preNum[right] - (preNum[left] * powOf10[len]) % MOD + MOD) % MOD;
            long long sum = preSum[right] - preSum[left];
            ans.push_back((x * sum) % MOD);
        }
        return ans;
    }
};