// Question Link :- https://www.geeksforgeeks.org/problems/find-xor-of-numbers-from-l-to-r/1
// Find XOR of numbers from L to R


// Approach - 1 (1005 /2005 test case passed)
// T.C = O(n)
// S.C = O(1)
class Solution {
    public:
    int findXOR(int left, int right) {
        int ans = 0;
        for(int i = left; i<=right; i++) {
            ans  = ans ^ i;
        }
        return ans;
    }
};


// Approach - 2
// T.C = O(1)
// S.C = O(1)
class Solution {
    public:
    int func(int n) {
        if(n % 4 == 1) {
            return 1;
        } if(n % 4 == 2) {
            return n + 1;
        } if(n % 4 == 3) {
            return 0;
        } else {
            return n;
        }
    }
    
    int findXOR(int left, int right) {
        return func(left-1) ^ func(right);
    }
};