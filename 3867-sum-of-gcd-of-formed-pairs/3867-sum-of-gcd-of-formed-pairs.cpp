class Solution {
public:
    long long gcdSum(vector<int>& nums) {

        vector<int> prefixGcd;
        int mx = nums[0];

        for (int num : nums) {
            mx = max(mx, num);
            prefixGcd.push_back(gcd(num, mx));
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        int left = 0;
        int right = prefixGcd.size() - 1;
        long long sum = 0;
        while (left < right) {
            sum += gcd(prefixGcd[left], prefixGcd[right]);
            left++;
            right--;
        }
        return sum;
    }
};