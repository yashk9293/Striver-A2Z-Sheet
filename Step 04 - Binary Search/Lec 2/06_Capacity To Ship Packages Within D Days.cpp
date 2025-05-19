// Question Link :- https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
// Capacity To Ship Packages Within D Days

// Similar Questions -
// https://leetcode.com/problems/minimum-time-to-complete-trips/ (codestorywithMIK)
// https://leetcode.com/problems/koko-eating-bananas/ (codestorywithMIK)

// Binary Search (Optimal Solution)
// T.C = O(logN)
// S.C = O(1)
class Solution {
public:
    bool isPossible(vector<int>& weights, int mid, int days) {
        int currDays = 1;
        int sum = 0;
        for(int i = 0; i < weights.size(); i++) {
            sum += weights[i];
            if(sum > mid) {
                currDays++;
                sum = weights[i];
            }
        }
        return currDays <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int sum = 0;
        for(int i=0; i<weights.size(); i++) {
            sum += weights[i];
        }
        int r = sum;
        // int r = accumulate(weights.begin(), weights.end(), 0);
        while(l <= r) {
            int mid = l + (r-l)/2;
            if(isPossible(weights, mid, days)) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};






// Naive Approach (for brute force in binary search, always run a loop from l to r, which will give O(N) complexity
// where as running loop from l to r via mid, gives O(logN) complexity in binary search.)
// T.C = O(N)
// S.C = O(1)
class Solution {
public:
    bool isPossible(vector<int>& weights, int mid, int days) {
        int currDays = 1;
        int sum = 0;
        for(int i = 0; i < weights.size(); i++) {
            sum += weights[i];
            if(sum > mid) {
                currDays++;
                sum = weights[i];
            }
        }
        return currDays <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int sum = 0;
        for(int i=0; i<weights.size(); i++) {
            sum += weights[i];
        }
        int r = sum;
        // int r = accumulate(weights.begin(), weights.end(), 0);
        for (int i = l; i <= r; i++) {
            if (isPossible(weights, i, days)) {
                return i;
            }
        }
        //dummy return statement:
        return -1;
    }
};