class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for (int i = 0; i < nums2.size(); i++) {
            nums1.push_back(nums2[i]);
        }
        sort(nums1.begin(), nums1.end());
        float mid = nums1.size() / 2, ans;
        if (nums1.size() % 2 == 0) {
            ans = (nums1[mid] + nums1[mid - 1]);
            ans /= 2;
        } else
            ans = nums1[mid];
        return ans;
    }
};