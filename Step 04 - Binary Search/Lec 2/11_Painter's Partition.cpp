// Question Link :- https://www.naukri.com/code360/problems/painter-s-partition-problem_1089557
// Painter's Partition Problem
// (largest sum of any subarray is minimized.)


// Similar problems with same code
// https://www.naukri.com/code360/problems/allocate-books_1090540 [9]
// https://leetcode.com/problems/split-array-largest-sum/ [10]





// Brute Force (same as 09.cpp)


// Binary Search (Optimal Solution)
// T.C = O(N * log(sum(arr)-max(arr[])+1))) 
// S.C = O(1)
bool countPainters(vector<int> &arr, int mid, int k) {
    int n = arr.size();
    int painters = 1;
    long long boardSum = 0;
    for (int i = 0; i < n; i++) {
        boardSum += arr[i];
        if(boardSum > mid) {   //add pages to next student
            painters++;
            boardSum = arr[i];
        }
    }
    return painters <= k;
}

int findLargestMinDistance(vector<int> &boards, int k) {
    int n = boards.size();
    if (k > n) {
        return -1;
    }
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);
    while (low <= high) {
        int mid = (low + high) / 2;
        if (countPainters(boards, mid, k)) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

