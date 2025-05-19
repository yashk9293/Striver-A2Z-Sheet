// Question Link - https://www.naukri.com/code360/problems/merge-two-sorted-arrays-without-extra-space_6898839
// Merge Two Sorted Arrays Without Extra Space

// T.C = O(min(n, m)) + O(n*logn) + O(m*logm)
// S.C = O(1)
void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &arr1, vector<long long> &arr2){
	int n = arr1.size();
	int m = arr2.size();

	int left = n - 1;
    int right = 0;

    // Swap the elements until arr1[left] is smaller than arr2[right]
    while (left >= 0 && right < m) {
        if (arr1[left] > arr2[right]) {
            swap(arr1[left], arr2[right]);
            left--, right++;
        }
        else {        // If at any point, arr1[left] <= arr2[right], it means,
            break;    // arr1[left] (largest in arr1) is already smaller or equal to arr2[right] (smallest in arr2)
        }             // This means that further swaps are unnecessary.
    }
    
    // Sort arr1[] and arr2[] individually:
    sort(arr1.begin(), arr1.begin() + n);
    sort(arr2.begin(), arr2.begin() + m);
}