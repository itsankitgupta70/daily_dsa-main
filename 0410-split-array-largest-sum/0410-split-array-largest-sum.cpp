class Solution {
public:
    bool splitable(vector<int>& nums, int mid, int k) {
        int x = 1;
        long long n = 0;
        for (int num : nums) {
            if (n + num <= mid) {
                n += num;
            } else {
                x++;
                if (x > k) {
                    return false;
                }
                n = num;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < k) {
            return -1;
        }
        long long low = *max_element(nums.begin(), nums.end());
        long long high = accumulate(nums.begin(), nums.end(), 0LL);
        long long res = -1;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (splitable(nums, mid, k)) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return (int)res;
    }
};