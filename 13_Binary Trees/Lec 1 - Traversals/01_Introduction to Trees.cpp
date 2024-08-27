// Question Link :- https://www.geeksforgeeks.org/problems/introduction-to-trees/1
// Introduction to Trees


// Method 1
// T.C = O(log N)
// S.C = O(1)
class Solution {
  public:
    int countNodes(int i) {
        return pow(2, i-1);
    }
};


// Method 2
// T.C = O(1)
// S.C = O(1)
class Solution {
  public:
    int countNodes(int i) {
        return (1 << (i-1));
    }
};


// Method 3
// T.C = O(N)
// S.C = O(N) -> recursion stack
class Solution {
  public:
    int countNodes(int i) {
        if(i == 1) {
            return 1;
        }
        return 2 * countNodes(i-1);
    }
};
