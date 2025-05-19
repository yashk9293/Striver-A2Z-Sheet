// Question Link :- https://www.geeksforgeeks.org/problems/bit-manipulation-1666686020/1
// Bit Manipulation

class Solution {
  public:
    void bitManipulation(int num, int i) {
        int f1 = (num>>i-1) & 1;
        int f2 = num | (1<<i-1);
        int f3 = num & ~(1<<i-1);
        cout<< f1 << " " << f2 << " " << f3;
    }
};