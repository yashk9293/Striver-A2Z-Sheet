// Question Link :- https://leetcode.com/problems/divide-two-integers/description/
// Divide Two Integers

// Brute Force
// T.C = O(dividev/divisor)
// S.C = O(1)
class Solution {
public:
    int divide(int dividend, int divisor) {
        // edge case
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        int dvd = abs(dividend), dvs = abs(divisor);
        long sum = dvs, cnt = 0;
        while(sum <= dvd) {
            sum += dvs;
            cnt ++;
        }
        if((dividend >= 0 && divisor > 0) || (dividend <= 0 && divisor < 0)) {
            return cnt;
        } else {
            return -cnt;
        }
    }
};



// Better Approach
// T.C = O(log(N)^2) ~ O(logN)
// S.C = O(1)
class Solution {
public:
    int divide(int dividend, int divisor) {
        // corner case, if -2^31 / -1 = 2^31, then we will return INT_MAX(2^31-1)
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        long dvd = abs(dividend), dvs = abs(divisor), ans = 0;
        while(dvd >= dvs) {    // O(log2N)
            int cnt = 0;
            while((dvs << cnt+1) <= dvd) {   // it can go upto 1 - - - 31, So (log2N)
                cnt++;
            }
            ans += (1 << cnt);
            dvd -= (dvs << cnt);   // dvs * 2^cnt
        }
        if((dividend >= 0 && divisor > 0) || (dividend <= 0 && divisor < 0)) {
            return ans;
        } else {
            return -ans;
        }
    }
};