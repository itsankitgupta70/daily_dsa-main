// https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1

class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        if (n < k) return 0;
        int low = 0, high = k - 1, sum = 0;
        for(int i = low; i <= high; i++){
            sum = sum + arr[i];
        }
        int res = sum;
        while(high < n - 1){
            low++;
            high++;
            sum = sum - arr[low-1] + arr[high];
            res = max(res , sum);
        }
        return res;
    }
};