class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int oddMin = INT_MAX;
        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[i] % 2 != 0) {
                if (nums1[i] < oddMin) {
                    oddMin = nums1[i];
                }
            }
        }
        if (oddMin == INT_MAX)
            return true;
        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[i] % 2 == 0 && nums1[i] - oddMin < 1) {
                return false;
            }
        }
        return true;
    }
};