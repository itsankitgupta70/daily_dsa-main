class Solution {
public:
    int countS(int m, int n, int mid) {
        int count = 0;

        for (int col = 1; col <= n; col++) {
            count += min(m, mid / col);
        }

        return count;
    }
    int findKthNumber(int m, int n, int k) {
        int low = 1;
        int high = m * n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int ans = countS(m, n, mid);
            if (ans < k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};