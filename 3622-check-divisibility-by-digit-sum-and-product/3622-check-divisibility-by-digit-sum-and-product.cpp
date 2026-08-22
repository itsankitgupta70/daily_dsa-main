class Solution {
public:
    bool checkDivisibility(int n) {
        int original = n;
        int sum = 0;
        int mul = 1;

        while (n > 0) {
            int digit = n % 10;
            sum += digit;
            mul *= digit;
            n /= 10;
        }

        int total = sum + mul;

        return original % total == 0;
    }
};