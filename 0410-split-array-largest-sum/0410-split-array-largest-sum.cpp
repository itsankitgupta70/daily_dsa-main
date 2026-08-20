class Solution {
public:
    bool splitable(vector<int>& nums, long long mid, int k) {
        int parts = 1;
        long long sum = 0;

        for (int num : nums) {
            if (sum + num <= mid) {
                sum += num;
            } else {
                parts++;

                if (parts > k)
                    return false;

                sum = num;
            }
        }

        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        long long low = *max_element(nums.begin(), nums.end());
        long long high = accumulate(nums.begin(), nums.end(), 0LL);

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (splitable(nums, mid, k))
                high = mid - 1;
            else
                low = mid + 1;
        }

        return low;
    }
};