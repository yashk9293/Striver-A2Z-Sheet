// Question Link :- https://leetcode.com/problems/palindrome-number/description/
// Palindrome Number


// Approach - 1 : Convertion to string
// T.C = O(logx)
// S.C = O(d) i.e. O(log10(x))
class Solution {
public:
    bool isPalindrome(int x) {
        string str = to_string(x);  // O(log10(x)) (since x has roughly log10(x) digits).
        int n = str.size();
        for(int i = 0; i < n/2; i++) { // O(d/2) ~ O(d)
            if(str[i] != str[n-i-1]) {
                return false;
            }
        }
        return true;
    }
};



// T.C = O(logx)
// S.C = O(1)
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        long long revNum = 0;
        int num = x;
        while(num) {
            int digit = num % 10;
            revNum = (revNum * 10) + digit;
            num = num/10;
        }
        if(x == revNum) {
            return true;
        }
        return false;
    }
};