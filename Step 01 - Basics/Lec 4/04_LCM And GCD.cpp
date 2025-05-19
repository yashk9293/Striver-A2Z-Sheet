// Question Link :- https://www.geeksforgeeks.org/problems/lcm-and-gcd4516/1
// LCM And GCD


// Euclidean Algorithm
// T.C = O(log(min(a, b)))
// S.C = O(1)
class Solution {
  public:
    vector<int> lcmAndGcd(int a, int b) {
        int a1 = a, b1 = b;
        while (b != 0) {  // O(log(min(a, b)))
            int temp = a % b;
            a = b;
            b = temp;
        }
        int gcd = a;
        int lcm = a1*b1/gcd;
        return {lcm, gcd};
    }
};


// T.C = O(log(min(a, b)))
// S.C = O(log(min(a, b)))  due to recursion stack
class Solution {
  public:
    int gcd_(int a, int b) {
        if(b==0) {
            return a;
        }
        return gcd_(b, a%b);
    }

    vector<int> lcmAndGcd(int a, int b) {
        int gcd = gcd_(a, b);
        int lcm = a*b/gcd;
        return {lcm, gcd};
    }
};