// Question Link :- 
// Sum 1 to n Divisors


// Brute Force
// T.C = O(n^2)
// S.C = O(1)
class Solution {
  public:
    int sumDivisors(int n) {
        int sum = 0;
        for (int i = 1; i <= n; i++) { 
            if (n % i == 0) { 
                sum += i; 
            }
        }
        return sum; 
    }

    int sumOfDivisors(int n) {
        int answer = 0;
        for(int i=1; i<=n; i++) {
            answer += sumDivisors(i);
        }
        return answer;
    }
};



// Better Approach
// T.C = O(n*sqrt(n))
// S.C = O(1)
class Solution {
  public:
    int sumDivisors(int n) {
        int sum = 0;
        int sqrtN = sqrt(n); 
        for (int i = 1; i <= sqrtN; i++) { 
            if (n % i == 0) {
                sum += i;
                if (i != n / i) {
                    sum += n/i;
                }
            }
        }
        return sum; 
    }

    int sumOfDivisors(int n) {
        int answer = 0;
        for(int i=1; i<=n; i++) {
            answer += sumDivisors(i);
        }
        return answer;
    }
};