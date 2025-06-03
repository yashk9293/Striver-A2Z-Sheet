// Question Link :- https://www.geeksforgeeks.org/problems/longest-common-substring1452/1
// Longest Common Substring

// Notes:- https://www.geeksforgeeks.org/longest-common-substring-dp-29/

// T.C = O(n*m)
// S.C = O(n*m)

// IMPORTANT - in this question the final answer could be anywhere in the matrix, not always in
//             t[n][m] last row col. So that's why we ar using ans variable to store the max value.



// Approach - 1 (Recursion + Memoization)
// T.C = O(n*m) [since each state is computed once]
// S.C = O(n*m)
class Solution {
public:
    int solve(string &text1, string &text2, int n, int m, int &maxLength, vector<vector<int>> &t) {
        if (n == 0 || m == 0) {
            return 0;
        }
        if (t[n][m] != -1) {
            return t[n][m];
        }
        
        if (text1[n-1] == text2[m-1]) {
            t[n][m] = 1 + solve(text1, text2, n-1, m-1, maxLength, t);
            maxLength = max(maxLength, t[n][m]);    // Update maximum length
        } else {
            t[n][m] = 0;    // Reset the length since it's a substring, not subsequence
        }

        solve(text1, text2, n-1, m, maxLength, t);
        solve(text1, text2, n, m-1, maxLength, t);

        return t[n][m];
    }

    int longestCommonSubstr(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        int ans = 0;
        vector<vector<int>> t(n + 1, vector<int>(m + 1, -1));

        solve(text1, text2, n, m, ans, t);

        return ans;
    }
};




// Approach - 2 (Tabulation)
// (using global 'ans' variable)
class Solution{
    public:
    int longestCommonSubstr (string S1, string S2, int n, int m) {
        int ans = 0;
        int t[n+1][m+1];
        // base condition
        for(int i=0; i<n+1; i++) {
            for(int j=0; j<m+1; j++) {
                if(i==0 || j==0) {
                  t[i][j] = 0;
                }
            }
        }
        // choice diagram
        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(S1[i-1] == S2[j-1]){
                  t[i][j] = 1 + t[i-1][j-1];
                  ans = max(ans, t[i][j]);   // modification
                }
                else {
                   t[i][j] = 0;
                }
            }
        }
        return ans;
    }
};




// OR
class Solution{
    public:
    int longestCommonSubstr (string S1, string S2, int n, int m) {
        int t[n+1][m+1];
        // base condition
        for(int i=0; i<n+1; i++) {
            for(int j=0; j<m+1; j++) {
                if(i==0 || j==0) {
                  t[i][j] = 0;
                }
            }
        }
        // choice diagram
        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(S1[i-1] == S2[j-1]){
                  t[i][j] = 1 + t[i-1][j-1];
                }
                else {
                   t[i][j] = 0;
                }
            }
        }
        int ans = INT_MIN;
    	for (int i = 0; i <= n; i++) {
    		for (int j = 0; j <= m; j++) {
    			ans = max(ans, t[i][j]);
    		}
    	}
    	return ans;
    }
};
