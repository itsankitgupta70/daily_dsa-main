class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0;
        int place = 1;
        int sum_digits = 0;
        while (n > 0) {
            int digit = n % 10;
            n /= 10;
            if (digit == 0)
                continue;
            x = digit * place + x;
            sum_digits += digit;
            place *= 10;
        }
        return x * sum_digits;
    }
};