class Solution {
public:
    int maximumLengthSubstring(string s) {
         int n = s.size();
        unordered_map<char, int> freq;
        int i = 0;
        int j = 0;
        int result = 0;
        int cp = 0;
        while (j < n) {
            freq[s[j]]++;
            if (freq[s[j]] == 2 + 1) {
                cp++;
            }
            if (cp > 0) {
                freq[s[i]]--;
                if (freq[s[i]] == 2) {
                    cp--;
                }
                i++;
            }
            if (cp == 0) {
                result = max(result, j - i + 1);
            }
            j++;
        }
        return result;
    }
};