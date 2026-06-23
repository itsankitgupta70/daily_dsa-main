class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int ans = 0;

        for (int num : nums) {
            ans += freq[num - k];
            ans += freq[num + k];

            freq[num]++;
        }

        return ans;
    }
};