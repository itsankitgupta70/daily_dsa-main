class Solution {
public:
    bool canEat(vector<int>& piles, int mid, int h) {
        int actualHours = 0;

        for (int& pile : piles) {
            actualHours += pile / mid;

            if (pile % mid != 0) {
                actualHours++;
            }
            if (actualHours > h)
                return false;
        }
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while (low < high) {
            // per hour number of banana can eat
            int mid = low + (high - low) / 2;

            if (canEat(piles, mid, h)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};