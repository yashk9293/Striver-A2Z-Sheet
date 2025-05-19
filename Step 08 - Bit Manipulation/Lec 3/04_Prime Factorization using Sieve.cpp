// Question Link :- https://www.geeksforgeeks.org/problems/prime-factorization-using-sieve/1
// Prime Factorization using Sieve


// Approach - 1
// T.C = O(N)
// S.C = O(m)
class Solution {
  public:
    void sieve() {}

    vector<int> findPrimeFactors(int n) {
        vector<int> result;
        for(int i=2; i<=n; i++) {
            if(n%i == 0) {
                while(n%i == 0) {
                    result.push_back(i);
                    n = n/i;
                }
            }
        }
        return result;
    }
};



// Approach - 2
// T.C = O(sqrt(n))
// S.C = O(m)
class Solution {
  public:
    void sieve() {}

    vector<int> findPrimeFactors(int n) {
        vector<int> result;
        for(int i=2; i*i<=n; i++) {
            if(n%i == 0) {
                while(n%i == 0) {
                    result.push_back(i);
                    n = n/i;
                }
            }
        }
        if(n != 1) {
            result.push_back(n);
        }
        return result;
    }
};