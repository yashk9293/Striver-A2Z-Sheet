// Question Link :- https://leetcode.com/problems/search-a-2d-matrix-ii/
// Search a 2D Matrix II


// Approach - 1 (Brute Force)
// T.C = O(m*n)
// S.C = O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        // Brute force: check every element
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == target) {
                    return true;
                }
            }
        }
        return false;
    }
};



// Approach - 2 (Binary Search)
// T.C = O(m*logn)
// S.C = O(1)
class Solution {
public:
    bool binarySearchRow(vector<int>& row, int target) {
        int left = 0, right = row.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (row[mid] == target) {
                return true;
            } else if (row[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (auto& row : matrix) {
            if (binarySearchRow(row, target)) {
                return true;
            }
        }
        return false;
    }
};



// Optimal Solution (Using Pointers)
// T.C = O(logn)
// S.C = O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0;
        int j = n-1;
        while(i < m && j>=0 ) {
            if(matrix[i][j] == target) {
                return true;
            }
            if(matrix[i][j] < target){
                i++;
            } else if(matrix[i][j] > target) {
                j--;
            }
        }
        return false;
    }
};