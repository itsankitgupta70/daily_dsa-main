class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int n = nums.size();
        int j = 0;
        for (int i = nums[0]; i < nums[n - 1]; i++) {
            if (i == nums[j]) {
                j++;
                continue;
            } else {
                ans.push_back(i);
            }
        }
        return ans;
    }
};