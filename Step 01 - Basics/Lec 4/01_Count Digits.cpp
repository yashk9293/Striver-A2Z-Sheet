// Question Link :- https://www.geeksforgeeks.org/problems/count-digits5716/1
// Count Digits


// T.C = O(log10(n)) In the worst case, n has at most log₁₀(n) + 1 digits
// S.C = O(1)
class Solution {
  public:
    int evenlyDivides(int n) {
        int cnt = 0;
        int num = n;
        while(num) {
            int digit = num%10;
            if(digit != 0 && n % digit == 0) {
                cnt++;
            }
            num = num/10;
        }
        return cnt;
    }
};




// Question Link :- https://www.geeksforgeeks.org/program-count-digits-integer-3-different-methods/
// Count Digits


// Brute Force
// T.C = O(log10(n)) In the worst case, n has at most log₁₀(n) + 1 digits
// S.C = O(1)
int countDigits(int n) {
    int cnt = 0;
    while(n > 0){
        cnt = cnt + 1;
        n = n / 10;
    }
    return cnt;
}


// Optimal Approach
// T.C = O(1)
// S.C = O(1)
int countDigits(int n) {
    return floor(log10(n) + 1);
}