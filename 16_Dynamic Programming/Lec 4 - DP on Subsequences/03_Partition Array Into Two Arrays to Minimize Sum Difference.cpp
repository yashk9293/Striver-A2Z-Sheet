// Question Link :- https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/
// Partition Array Into Two Arrays to Minimize Sum Difference

// Note :- 1 <= n <= 15
// So array size could be of 2 - 30 (as array size if 2*n)

// Brute Force
// Calculate all the subset of the array and when subset size is n/2,
// then calculate (totalSum - 2*sum)
// T.C = O(2^N) where N = 2*n size



// Better Approach (Meet in the Middle)
// T.C = O(2^n * log (2^n)), where n in worst case is 15.
class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int N = nums.size(), sum = 0;
        sum = accumulate(nums.begin(), nums.end(), 0);
        int n = N/2;
        vector<vector<int>> left(n+1), right(n+1);

		//storing all possible sum in left and right part
        for(int mask = 0; mask<(1<<n); ++mask){
            int sz = 0, curSum1 = 0, curSum2 = 0;
            for(int i=0; i<n; ++i){
                if(mask & (1<<i)) {
                    sz++;
                    curSum1 += nums[i];
                    curSum2 += nums[i+n];
                }
            }
            left[sz].push_back(curSum1);
            right[sz].push_back(curSum2);
        }

        for(int i=0; i < n; i++) {
            sort(right[i].begin(), right[i].end());    // as we'll perform binary search on right so we have to sort it first
        }
        // for i = n case, taking all element from either left or either right
        int res = min(abs(sum - 2*left[n][0]), abs(sum - 2*right[n][0]));

		// iterating over 'left' part
        for(int i=1; i<n; i++) {
            for(auto &a : left[i]) {
                int b = (sum - 2*a)/2;
                int right_idx = n-i;
                auto &v = right[right_idx];
                auto itr = lower_bound(v.begin(), v.end(), b); //binary search over right part
                
                if(itr != v.end()) {
                    res = min(res, abs(sum - 2*(a + *itr)));
                }              
            }
        }
        return res;
    }
};
