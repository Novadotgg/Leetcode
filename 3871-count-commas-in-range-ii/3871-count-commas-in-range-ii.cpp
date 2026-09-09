class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        long long start = 1000;
        long long commas = 1;

        while (start <= n) {
            long long end;

            // Avoid overflow when calculating start * 1000
            if (start > n / 1000) {
                end = n;
            } else {
                end = min(n, start * 1000 - 1);
            }

            ans += (end - start + 1) * commas;

            // Move to next comma range
            if (start > n / 1000)
                break;

            start *= 1000;
            commas++;
        }

        return ans;
    }
};