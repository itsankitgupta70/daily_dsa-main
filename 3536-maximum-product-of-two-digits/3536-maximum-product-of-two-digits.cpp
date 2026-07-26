class Solution {
public:
    int maxProduct(int n) {
        string str = to_string(n);
        sort(str.begin(), str.end());
        int s = str.size();
        int ans = (str[s - 1] - '0') * (str[s - 2] - '0');
        return ans;
    }
};