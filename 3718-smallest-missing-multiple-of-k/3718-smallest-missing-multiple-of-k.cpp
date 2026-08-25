class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        bool present[101] = {};

        for (int num : nums)
            present[num] = true;

        for (int x = k; x <= 100; x += k) {
            if (!present[x])
                return x;
        }

        return ((100 / k) + 1) * k;
    }
};