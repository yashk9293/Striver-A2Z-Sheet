// Question Link :- https://www.geeksforgeeks.org/problems/sum-of-first-n-terms5843/1
// Sum of first n terms


// Iterative Approach
// T.C = O(n)
// S.C = O(1)
class Solution {
  public:
    int sumOfSeries(int n) {
        int ans = 0;
        for(int i=1; i<=n; i++) {
            ans += pow(i, 3);
        }
        return ans;
    }
};



// Recursive Approach
// T.C = O(n)
// S.C = O(n)
class Solution {
  public:
    int sumOfSeries(int n) {
        if(n==0) {
            return 0;
        }
        return n*n*n + sumOfSeries(n-1);
    }
};



// Optimal Approach
// T.C = O(1)
// S.C = O(1)
class Solution {
  public:
    int sumOfSeries(int n) {
        return (n*(n+1)/2)*(n*(n+1)/2);
    }
};