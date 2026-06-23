class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        unordered_map<char, int> firstPos;

        for (int i = 0; i < s.size(); i++) {

            if (firstPos.count(s[i])) {

                if (i - firstPos[s[i]] - 1 != distance[s[i] - 'a'])
                    return false;
            } else {
                firstPos[s[i]] = i;
            }
        }

        return true;
    }
};