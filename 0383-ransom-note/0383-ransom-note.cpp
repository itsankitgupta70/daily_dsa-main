class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> need(26, 0);
        for (auto& ransom : ransomNote) {
            need[ransom - 'a']++;
        }
        vector<int> have(26, 0);
        for (auto& mag : magazine) {
            have[mag - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (have[i] < need[i]) {
                return false;
            }
        }
        return true;
    }
};