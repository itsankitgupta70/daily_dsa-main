class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;
        while (true) {
            if (s[i] == ' ') {
                i--;
            } else {
                break;
            }
        }
        int count = 0;
        while (true) {
            if (s[i] != ' ') {
                count++;
                if (i == 0) {
                    return count;
                } else {
                    i--;
                }
            } else {
                break;
            }
        }
        return count;
    }
};