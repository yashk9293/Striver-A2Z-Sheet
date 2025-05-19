// Question Link :- https://www.geeksforgeeks.org/problems/generate-all-binary-strings/1
// Generate all binary strings


// T.C = O(1.618^n)
// In the worst case (without the consecutive '1' restriction), there would be 2^N binary strings.
// S.C = O(1.618^n*n) (Storing results + recursion stack)
class Solution{
public:
    void solve(int i, int num, string temp, vector<string> &res) {
        if(i >= num) {
            res.push_back(temp);
            return;
        }
        // if you pass temp by reference value then see line 16 and 18
        solve(i+1, num, temp + "0", res);
        if(temp.empty() || temp.back() != '1') {
            solve(i+1, num, temp + "1", res);
        }
    }

    vector<string> generateBinaryStrings(int num){
        vector<string> res;
        string temp = "";
        solve(0, num, temp, res);
        
        return res;
    }
};




// Why Use Reference (string &temp)?
// It avoids creating unnecessary string copies at each recursion step.

class Solution {
public:
    void solve(int i, int num, string &temp, vector<string> &res) {
        if (i >= num) {
            res.push_back(temp);
            return;
        }
        
        // Choose '0'
        temp.push_back('0');  // Modify temp in place
        solve(i + 1, num, temp, res);
        temp.pop_back();  // Backtrack

        // Choose '1' only if the last character is not '1'
        if (temp.empty() || temp.back() != '1') {
            temp.push_back('1');
            solve(i + 1, num, temp, res);
            temp.pop_back();  // Backtrack
        }
    }

    vector<string> generateBinaryStrings(int num) {
        vector<string> res;
        string temp;
        solve(0, num, temp, res);
        return res;
    }
};
