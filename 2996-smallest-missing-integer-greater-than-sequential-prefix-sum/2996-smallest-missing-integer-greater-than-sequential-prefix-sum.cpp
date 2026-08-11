class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1] + 1) {
                break;
            } else {
                ans += nums[i];
            }
        }
        while (true) {
            auto it = find(nums.begin(), nums.end(), ans);
            if (it != nums.end()) {
                ans++;
            } else {
                break;
            }
        }
        return ans;
    }
};