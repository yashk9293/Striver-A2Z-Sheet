// Question Link - https://leetcode.com/problems/pascals-triangle/
// Pascal's Triangle

// Method - 1
// t.c = O(n^2)
// s.c = O(1)  In this case, we are only using space to store the answer. That is why space complexity can still be considered as O(1).
class Solution {
public:
    vector<int> generateRow(int n) {
        long long ans = 1;
        vector<int> ansRow;
        ansRow.push_back(1); //inserting the 1st element

        //calculate the rest of the elements:
        for (int i = 1; i < n; i++) {
            ans = ans * (n - i);
            ans = ans / i;
            ansRow.push_back(ans);
        }
        return ansRow;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int row = 1; row <= numRows; row++) {
            ans.push_back(generateRow(row));
        }
        return ans;
    }
};


// Method - 2
// t.c = O(n^2)
// s.c = O(numRows)
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        vector<int> prevRow;
        
        for (int i = 0; i < numRows; i++) {
            vector<int> currentRow(i + 1, 1);
            
            for (int j = 1; j < i; j++) {
                currentRow[j] = prevRow[j - 1] + prevRow[j];
            }
            result.push_back(currentRow);
            prevRow = currentRow;
        }
        return result;
    }
};