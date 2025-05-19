#include <iostream>
#include <vector>

using namespace std;

// Upper Bound: First index where arr[i] > target

int upperBound(vector<int>& nums, int target) {
    int n = nums.size();
    int l = 0, r = n - 1;
    
    // find upper bound
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] > target) { 
            r = mid - 1; 
        } else {
            l = mid + 1; 
        }
    }
    return l;
}

int main() {
    vector<int> arr = {1, 2, 4, 4, 4, 6, 7, 9};  // Sorted input array
    int target;

    cout << "Enter the target value: ";
    cin >> target;

    int ub = upperBound(arr, target);

    cout << "Upper Bound index: " << ub << endl;

    // Show results if within bounds
    if (ub < arr.size()) {
        cout << "Upper Bound value: " << arr[ub] << endl;
    } else
        cout << "Upper Bound value not found in array." << endl;

    return 0;
}
