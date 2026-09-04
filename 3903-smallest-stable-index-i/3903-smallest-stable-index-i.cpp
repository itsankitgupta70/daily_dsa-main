class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> min_i(n);
        int mini = INT_MAX;
        for (int i = n - 1; i >= 0; i--) {
            mini = min(mini, nums[i]);
            min_i[i] = mini;
        }
        int max_i = nums[0];
        for (int i = 0; i < n; i++) {
            max_i = max(max_i, nums[i]);
            if (max_i - min_i[i] <= k) {
                return i;
            }
        }
        return -1;
    }
};