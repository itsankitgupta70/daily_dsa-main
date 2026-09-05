class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> mino(n);
        mino[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            mino[i] = min(nums[i], mino[i + 1]);
        }
        int maxo = nums[0];
        for (int i = 0; i < n; i++) {
            maxo = max(nums[i], maxo);
            if (maxo - mino[i] <= k) {
                return i;
            }
        }
        return -1;
    }
};