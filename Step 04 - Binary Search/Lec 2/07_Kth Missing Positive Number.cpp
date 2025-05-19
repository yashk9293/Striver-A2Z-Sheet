// Question Link :- https://leetcode.com/problems/kth-missing-positive-number/
// Kth Missing Positive Number

// Naive Approach
// T.C = O(n)
// S.C = O(1)
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int num = 1;
        int i=0;
        while(i < n && k > 0) {
            if(num == arr[i]) {
                i++;
            } else {
                k--;
            }
            num++;
        }

        while(k--) {
            num++;
        }

        return num - 1;
    }
};




// Approach-2 (Binary Search)
// T.C = O(logN)
// S.C = O(1)
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int l = 0;
        int r = n-1;
        while(l <= r) {
            int mid = l + (r-l)/2;
            // nums[i] - original number that should be at index i
            if(arr[mid] - (mid+1) < k) {
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        return l + k;
    }
};