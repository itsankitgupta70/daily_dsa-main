class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1, -1};
        int first = 0, last = nums.size() - 1;
        while (first <= last) {
            int mid = first + (last - first) / 2;
            if (nums[mid] == target) {
                ans[0] = mid;
                last = mid - 1;
            } else if (nums[mid] < target) {
                first = mid + 1;
            } else {
                last = mid - 1;
            }
        }
        first = 0;
        last = nums.size() - 1;
        while (first <= last) {
            int mid = first + (last - first) / 2;
            if (nums[mid] == target) {
                ans[1] = mid;
                first = mid + 1;
            } else if (nums[mid] < target) {
                first = mid + 1;
            } else {
                last = mid - 1;
            }
        }
        return ans;
    }
};
