// Question Link :- https://www.geeksforgeeks.org/problems/find-all-factorial-numbers-less-than-or-equal-to-n3548/0
// Factorials Less than or Equal to n


// Brute Force Approach
// T.C = O(n^2)
// S.C = O(n)
class Solution {
  public:
    long long factorial(long long n) {
        if(n==0 || n==1) {
            return 1;
        }
        return n * factorial(n-1);
    }

    vector<long long> factorialNumbers(long long n) {
        vector<long long> ans;
        for(long long i=1; i<=n; i++){
            if(factorial(i) <= n){
                ans.push_back(factorial(i));
            }
            else {
                break;
            }
        }
        return ans;
    }
};



// Optimal Solution
// T.C = O(logn)
// S.C = O(logn)  The space complexity is also O(log n) due to storing the factorial numbers in the result vector.
class Solution {
  public:
    vector<long long> factorialNumbers(long long n) {
        vector<long long> ans;
        long long fact = 1;
        long long i = 1;
        while(fact <= n) {
            ans.push_back(fact);
            i++;
            fact = fact*i;
        }
        return ans;
    }
};