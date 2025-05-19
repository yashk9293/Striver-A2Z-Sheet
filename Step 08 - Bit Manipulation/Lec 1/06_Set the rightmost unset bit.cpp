// Question Link :- https://www.geeksforgeeks.org/problems/set-the-rightmost-unset-bit4436/1
// Set the rightmost unset bit

// T.C = O(1)
// S.C = O(1)

// Method - 1
class Solution {
  public:
    int setBit(int n) {
        return n | n+1;
    }
};


// Method - 2
class Solution {
  public:
    int setBit(int n) {
        n = ~n;
        return ~(n & n-1);
    }
};