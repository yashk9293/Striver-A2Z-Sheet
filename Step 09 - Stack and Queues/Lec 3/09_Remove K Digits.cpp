// Question Link :- https://leetcode.com/problems/remove-k-digits/
// Remove K Digits


// T.C = O(n)
// S.C = O(1)
class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size() == k) {
            return "0";
        }
        string result = "";       // it will act like a stack
        int n = num.length();
        
        for(int i = 0; i < n; i++) {
            while(result.length() > 0 && result.back() > num[i] && k > 0) {
                result.pop_back();
                k--;
            }
            result.push_back(num[i]);
        }
        // now we have made result in increasing order, and remaining k element should be deleted from the end to get smallest number
        while(result.length() > 0 && k > 0) {
            result.pop_back();
            k--;
        }
        // removing preceding zeros
        int idx = 0;
        while (idx < result.size() && result[idx] == '0') {
            idx++;
        }
        result = result.substr(idx);

        if(result == "") {
            return "0";
        }
        return result;
    }
};