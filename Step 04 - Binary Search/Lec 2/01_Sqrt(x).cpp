// Question Link :- https://leetcode.com/problems/sqrtx/
// Sqrt(x)

// T.C: O(log n)
// S.C: O(1)
class Solution {
public:
    int mySqrt(int x) {
        // For special cases when x is 0 or 1, return x.
        if (x == 0 || x == 1) {
            return x;
        }

        int low = 1, high = x;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            long long square = static_cast<long long>(mid) * mid;

            if (square == x) {
                return mid;
            } else if (square < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return int(round(high));
    }
};