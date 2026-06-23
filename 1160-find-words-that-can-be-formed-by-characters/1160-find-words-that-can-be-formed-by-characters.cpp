class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> ch_freq(26, 0);

        for (auto& ch : chars) {
            ch_freq[ch - 'a']++;
        }
        int ans = 0;
        for (auto& wo : words) {
            vector<int> wo_freq(26, 0);
            for (auto w : wo) {
                wo_freq[w - 'a']++;
            }
            bool canForm = true;
            for (int i = 0; i < 26; i++) {
                if (wo_freq[i] > ch_freq[i]) {
                    canForm = false;
                    break;
                }
            }
            if (canForm) {
                ans += wo.length();
            }
        }
        return ans;
    }
};