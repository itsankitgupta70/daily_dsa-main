class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int h = nums.size() - 1;

        while (l < h) {
            int mid = l + (h - l) / 2;

            // Make mid even
            if (mid % 2 == 1)
                mid--;

            if (nums[mid] == nums[mid + 1]) {
                // Pair is intact, single is on the right
                l = mid + 2;
            } else {
                // Pair is broken, single is on the left
                h = mid;
            }
        }

        return nums[l];
    }
};