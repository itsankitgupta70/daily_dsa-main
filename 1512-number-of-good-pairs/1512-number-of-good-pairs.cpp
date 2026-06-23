class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<int> count(mx+1, 0);
        for(auto& i:nums){
            count[i]++;
        }
        int ans = 0;
        for (int freq : count) {
            if (freq >= 2) {
                ans += freq * (freq - 1) / 2;
            }
        }
        return ans;
    }
};