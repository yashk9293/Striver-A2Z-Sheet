// Question Link :- https://www.geeksforgeeks.org/problems/prime-factors5052/1
// Prime Factors


// Brute Force
// T.C = O(N*sqrt(N))
// S.C = O(m)
class Solution{
	public:
	bool checkPrime(int n) {     // O(sqrt(N))
        int cnt = 0;
        for (int i=2; i*i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
	vector<int>AllPrimeFactors(int n) {
	    vector<int>result;
        for(int i=2; i<=n; i++) {    // O(N)
            if(n%i==0 && checkPrime(i)) {
                result.push_back(i);
            }
        }
       return result;
	}
};




// Better Approach
// T.C = O(N)
// S.C = O(m)
class Solution{
    public:
    vector<int>AllPrimeFactors(int n) {
        vector<int> result;
        for(int i=2; i<=n; i++) {
            if(n%i == 0) {
                result.push_back(i);
                while(n%i == 0) {
                    n = n/i;
                }
            }
        }
        return result;
    }
};





// Optimal Approach
// T.C = O(sqrt(N))
// S.C = O(m)
class Solution{
    public:
    vector<int>AllPrimeFactors(int n) {
        vector<int> result;
        for(int i=2; i*i<=n; i++) {   // modification 1: for(2 to sqrt(n))
            if(n%i == 0) {
                result.push_back(i);
                while(n%i == 0) {
                    n = n/i;
                }
            }
        }
        if(n != 1) {   // if the n is itself a prime, then add in the result
            result.push_back(n);
        }
        return result;
    }
};