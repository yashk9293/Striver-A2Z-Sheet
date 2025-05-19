// Question Link :- https://www.naukri.com/code360/problems/bubble-sort_980524
// Bubble Sort

// T.C = O(n^2)
// S.C = O(n)  recursive stack
#include <bits/stdc++.h> 
void bubbleSort(vector<int>& arr, int n) {
    if (n == 1) {
        return;
    }
    for (int i=0; i<n-1; i++) {
        if (arr[i] > arr[i+1]) {
            swap(arr[i],arr[i+1]);
        }
    }
    bubbleSort(arr, n - 1);
}