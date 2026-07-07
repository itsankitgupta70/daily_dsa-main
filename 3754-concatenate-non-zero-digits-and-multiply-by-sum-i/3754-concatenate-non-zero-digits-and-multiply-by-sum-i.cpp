class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);

        string temp = "";
        long long sum = 0;

        for (char c : s) {
            if (c != '0') {
                temp += c;
                sum += c - '0';
            }
        }

        long long x = (temp.empty()) ? 0 : stoll(temp);

        return x * sum;
    }
};