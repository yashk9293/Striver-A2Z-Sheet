// Question Link :- https://leetcode.com/problems/split-array-largest-sum/
// Split Array Largest Sum


// Similar problems with same code
// https://www.naukri.com/code360/problems/allocate-books_1090540 [9]
// https://www.naukri.com/code360/problems/painter-s-partition-problem_1089557 [11]





// Brute Force (same as 09.cpp)




// Binary Search (Optimal Solution)
// T.C = O(N * log(sum(arr)-max(arr[])+1))) 
// S.C = O(1)
class Solution {
public:
    int isPossible(vector<int> &arr, int mid, int k) {
        int n = arr.size();
        int partitions = 1;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            if(sum > mid) {   //add pages to next student
                partitions++;
                sum = arr[i];
            }
        }
        return partitions <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if (k > n) {
            return -1;
        }
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while (low <= high) {
            int mid = (low + high) / 2;
            if (isPossible(nums, mid, k)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};