// Question Link :- https://leetcode.com/problems/count-good-numbers/
// Count Good Numbers


// T.C = O(logN)
// S.C = O(logN)
class Solution {
public:
    long long mod = 1000000007;

    long long pow(long long x, long long n) { 
        if(n == 0) {
            return 1;
        }
        if(n < 0) {
            return (pow(1/x, -n)) % mod;
        }
        if(n%2 == 0) {
            return (pow((x*x)%mod, n/2)) % mod;
        } else {
            return ((x % mod) * (pow((x*x)%mod, (n-1)/2)) % mod) % mod;
        }
    }

    int countGoodNumbers(long long n) {
        long long evenPlaces = (n+1)/2;
        long long oddPlaces = n/2;
        // 0 2 4 6 8 - 5 even nos.
        // 2 3 5 7 - 4 prime nos.
        int ans = (int)(pow(5, evenPlaces)%mod * pow(4, oddPlaces)%mod) % mod;
        return ans;
    }
};