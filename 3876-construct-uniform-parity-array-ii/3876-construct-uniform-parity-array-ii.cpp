class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int oddMin = INT_MAX;

        for (int num : nums1) {
            if (num % 2 != 0)
                oddMin = min(oddMin, num);
        }

        if (oddMin == INT_MAX)
            return true;

        for (int num : nums1) {
            if (num % 2 == 0 && num < oddMin)
                return false;
        }

        return true;
    }
};