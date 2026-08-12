class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        int i = 0;
        int j = 0;
        int result = 0;
        int cp = 0;
        while (j < n) {
            freq[nums[j]]++;
            if (freq[nums[j]] == k + 1) {
                cp++;
            }
            if (cp > 0) {
                freq[nums[i]]--;
                if (freq[nums[i]] == k) {
                    cp--;
                }
                i++;
            }
            if (cp == 0) {
                result = max(result, j - i + 1);
            }
            j++;
        }
        return result;
    }
};