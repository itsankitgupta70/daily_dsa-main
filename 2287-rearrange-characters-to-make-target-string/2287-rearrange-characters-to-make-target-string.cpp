class Solution {
public:
    int rearrangeCharacters(string s, string target) {

        vector<int> s_freq(26, 0);

        for (auto& ch : s) {
            s_freq[ch - 'a']++;
        }
        int ans = INT_MAX;
        vector<int> t_freq(26, 0);
        for (auto& ch : target) {
            t_freq[ch - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (t_freq[i] > 0)
                ans = min(ans, s_freq[i] / t_freq[i]);
        }
        return ans;
    }
};