// Question Link :- https://www.geeksforgeeks.org/problems/subset-sums2234/1
// Subset Sums


[3 1 2] , n=3

{} -> 0                                      sum = 0 1 2 3 3 4 5 6
{3} -> 3
{1} -> 1
{2} -> 2
{3 1} -> 4
{3 2} -> 5
{1 2} -> 3
{3 1 2} -> 6


// Approach - 1 (Bit Manipulation)
// T.C = O(n*2^n)
// S.C = O(1)
class Solution {
  public:
    vector<int> subsetSums(vector<int> arr, int n) {
        vector<int> ans;
        for(int i=0; i<(1<<n); i++) {
            int sum = 0;
            for(int bit=0; bit< n; bit++) {
                if(i & 1<<bit) {
                    sum += arr[bit];
                }
            }
            ans.push_back(sum);
        }
        return ans;
    }
};





/*
                                     -------- 3 1 2, sum=0 --------
                                    /                              \
                          |        /                                \  |
                          v       /                                  \ v
                     -- 3 1 2, sum=3 --                           -- 3 1 2, sum=0 --
                |  /                    \   |                 |  /                   \   |
                V /                      \  V                 V /                     \  V
            3 1 2, sum=4                3 1 2, sum=3      3 1 2, sum=1               3 1 2, sum=0 
        |  /            \   |          /           \     /            \             /            \
        V /              \  V         /            |     |             |           /              \
   3 1 2 ,sum=6        3 1 2 ,sum=4  /             |     |             |           |              |
                                    /              |     |             |           |              |
                                |  /             | |     |           | |           |              |
                                V /              V |     |           V |           |              |
                           3 1 2 ,sum=5     3 1 2 ,sum=3 |      3 1 2  ,sum=1    | |              | |
                                                         |                       V |              | V
                                                       | |                  3 1 2 ,sum=2       3 1 2 ,sum=0
                                                       V |
                                                  3 1 2 ,sum=3
*/



// Approach - 2 (Recursion)
// T.C = O(2^n)
// S.C = O(2^n)
class Solution {
  public:
    void solve(vector<int>& nums, int i, int sum, vector<int>& ans) {
        // base case
        if(i>=nums.size()) {
            ans.push_back(sum);
            return;
        }
        // include
        solve(nums, i+1, sum+nums[i], ans);

        // exclude
        solve(nums, i+1, sum, ans);
    }

    vector<int> subsetSums(vector<int> nums, int n) {
        vector<int> ans;
        int sum = 0;
        solve(nums, 0, sum, ans);
        return ans;
    }
};
