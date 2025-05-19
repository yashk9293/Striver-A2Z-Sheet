// Question Link :- https://leetcode.com/problems/string-to-integer-atoi/description/
// String to Integer (atoi)

// T.C. = O(n)
// S.C. = O(1)
class Solution {
public:
    int myAtoi(string s) {
        if(s.length() == 0) {
            return 0;
        }
        int i = 0;
        // Step 1: Ignore leading whitespaces
        while(i<s.size() && s[i]== ' ') {
            i++;
        }
        s = s.substr(i); // i --> last of string, s = s.substr(i, s.length() - i);
        
        // Step 2: Handle sign
        int sign = 1;
        if (s[0] == '+' || s[0] == '-') {
            sign = (s[0] == '-') ? -1 : 1;
            i = 1;
        } else {
            i = 0;
        }

        // Step 3: Convert digits to integer
        long result = 0;
        while (i<s.size() && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');  // s[i]-'0' converts string integer's("3") into integer(3)

            // Step 4: Handle overflow and underflow
            if(sign == -1 && -1*result < INT_MIN) {
                return INT_MIN;
            }
            if(sign == 1 && result > INT_MAX) {
                return INT_MAX;
            }
            i++;
        }
        return result*sign;
    }
};