class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        // Binary search on the smaller array
        if (nums1.size() > nums2.size())
            swap(nums1, nums2);

        int n = nums1.size();
        int m = nums2.size();

        int low = 0;
        int high = n;

        while (low <= high) {

            // Cut in nums1
            int cut1 = low + (high - low) / 2;

            // Cut in nums2 so that left side has
            // half of all elements
            int cut2 = (n + m + 1) / 2 - cut1;

            // Elements immediately around the cuts
            int left1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];

            int right1 = (cut1 == n) ? INT_MAX : nums1[cut1];

            int left2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];

            int right2 = (cut2 == m) ? INT_MAX : nums2[cut2];

            // Correct partition
            if (left1 <= right2 && left2 <= right1) {

                // Odd total number of elements
                if ((n + m) % 2 == 1) {
                    return max(left1, left2);
                }

                // Even total number of elements
                return (max(left1, left2) + min(right1, right2)) / 2.0;
            }

            // nums1 cut is too far right
            if (left1 > right2) {
                high = cut1 - 1;
            }

            // nums1 cut is too far left
            else {
                low = cut1 + 1;
            }
        }

        return 0.0;
    }
};