// Question Link :- https://leetcode.com/problems/power-of-two/
// Power of Two

// Recursion
// T.C = O(logN)
// S.C = O(1)
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==1) {
            return true;
        }
        if(n%2==1) {
            return false;
        }
        if(n<1) {
            return false;
        }
        return isPowerOfTwo(n/2);
    }
};



// Iterative (for loop)
// T.C = O(1)
// S.C = O(1)
class Solution {
public:
    bool isPowerOfTwo(int n) {
        int num = 1;
        for(int i = 0; i <= 30; i++) {
            if(num == n) {
                return true;
            }
            if(num < INT_MAX/2) {
                num *= 2;
            }
        }
        return false;
    }
};




// Follow Up - without for loop or recursion

// Bit manipulation
// T.C = O(1)
// S.C = O(1)
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n > 0) && ((n & (n - 1)) == 0);
    }
};

// OR
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) {
            return false;
        }
        return __builtin_popcount(n) == 1;
    }
};
