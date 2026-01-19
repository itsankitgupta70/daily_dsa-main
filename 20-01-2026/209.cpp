// https://leetcode.com/problems/minimum-size-subarray-sum/description/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = 0, sum = 0, count = INT_MAX;

        while (high < n) {
            sum = sum + nums[high];
            while (sum >= target) {
                int len = high - low + 1;
                count = min(count, len);
                sum = sum - nums[low];
                low++;
            }
            high++;
        }
        return (count == INT_MAX) ? 0 : count;
    }
};