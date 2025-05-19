// Question Link :- https://leetcode.com/problems/minimum-bit-flips-to-convert-number/
// Minimum Bit Flips to Convert Number


// T.C = O(n)
// S.C = O(1)
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int a = start;
        int b = goal;
        int count = 0;
        while(a>0 || b>0){
            if((a&1) != (b&1)) {
                count++;
            }
            a = a>>1;
            b = b>>1;
        }
        return count;
    }
};




// T.C = O(logn) where n is the no. of bits
// S.C = O(1)
class Solution {
public:
    int minBitFlips(int start, int goal) {
        return __builtin_popcount(start^goal);
    }
};



// Brian Kernighan’s Algorithm
// T.C = O(logn)
// S.C = O(1)
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int result = start^goal;
        int count=0;
        while(result) {
            result = result & (result-1);
            count++;
        }
        return count;
    }
};