class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> freq;
        for (auto& c : s) {
            freq[c]++;
        }
        int i = 0;
        for (auto& c : s) {
            if (freq[c] == 1) {
                return i;
            } else {
                i++;
            }
        }
        return -1;
    }
};