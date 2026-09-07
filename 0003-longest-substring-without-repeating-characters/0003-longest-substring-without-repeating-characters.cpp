class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastSeen;
        int left = 0;
        int res = 0;
        for (int right = 0; right < s.size(); right++) {
            if (lastSeen.count(s[right])) {
                left = max(left, lastSeen[s[right]] + 1);
            }
            lastSeen[s[right]] = right;
            res = max(res, right - left + 1);
        }
        return res;
    }
};