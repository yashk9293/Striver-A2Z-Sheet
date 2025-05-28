// Question Link :- https://leetcode.com/problems/row-with-maximum-ones/description/
// Row With Maximum Ones


// T.C = O(n^2)
// S.C = O(1)
class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int maxi = 0, index = 0;
        for(int i=0; i<m; i++) {
            int cntOne = 0;
            for(int j=0; j<n; j++) {
                if(mat[i][j] == 1) {
                    cntOne++;
                }
            }
            if(cntOne > maxi) {
                maxi = cntOne;
                index = i;
            }
        }
        return {index, maxi};
    }
};



// If the matrix was sorted row wise, then it would have taken O(nlogn) time.
// T.C = O(n*log(n))
// S.C = O(1)
class Solution {
public:
    int lowerBound(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0, r = n - 1;

        // find lower bound
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] >= target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int maxi = 0, index = 0;
        for (int i = 0; i < m; i++) {
            int cntOne = n - lowerBound(mat[i], 1);
            if (cntOne > maxi) {
                maxi = cntOne;
                index = i;
            }
        }
        return {index, maxi};
    }
};
