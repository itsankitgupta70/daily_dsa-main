// https://leetcode.com/problems/squares-of-a-sorted-array/description/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        int k = n - 1, i = 0, j = n - 1;
        while (i <= j) {
            if (abs(nums[i]) > abs(nums[j])) {
                res[k] = nums[i] * nums[i];
                k--;
                i++;
            } else {
                res[k] = nums[j] * nums[j];
                k--;
                j--;
            }
        }
        return res;
    }
};
