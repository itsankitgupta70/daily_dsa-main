class Solution {
public:
    static constexpr int MOD = 1000000007;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<int> nonZeroCnt(n + 1, 0);     // non zero count karna hai
        vector<long long> concatPrefix(1, 0); // concatinated number
        vector<int> digitSumPrefix(1, 0);     // digits ke sum
        vector<long long> pow10(
            1, 1); // pow of 10 ko bhi save kar lo taki baar na calc ho

        for (int i = 0; i < n; i++) {
            nonZeroCnt[i + 1] = nonZeroCnt[i];

            int digit = s[i] - '0';

            if (digit) {
                nonZeroCnt[i + 1]++;

                concatPrefix.push_back((concatPrefix.back() * 10 + digit) % MOD);

                digitSumPrefix.push_back(digitSumPrefix.back() + digit);

                pow10.push_back(pow10.back() * 10 % MOD);
            }
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int left = nonZeroCnt[q[0]];
            int right = nonZeroCnt[q[1] + 1];

            long long x =
                (concatPrefix[right] - (concatPrefix[left] * pow10[right - left]) % MOD + MOD) % MOD;

            long long sum = digitSumPrefix[right] - digitSumPrefix[left];

            ans.push_back((x * sum) % MOD);
        }

        return ans;
    }
};