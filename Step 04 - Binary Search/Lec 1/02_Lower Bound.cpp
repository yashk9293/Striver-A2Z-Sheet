#include <iostream>
#include <vector>

using namespace std;

// Lower Bound: First index where arr[i] >= target
int lowerBound(vector<int>& nums, int target) {
    int n = nums.size();
    int l = 0, r = n-1;
    
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


int main() {
    vector<int> arr = {1, 2, 4, 4, 4, 6, 7, 9};  // Sorted input array
    int target;

    cout << "Enter the target value: ";
    cin >> target;

    int lb = lowerBound(arr, target);

    cout << "Lower Bound index: " << lb << endl;

    // Show results if within bounds
    if (lb < arr.size()) {
        cout << "Lower Bound value: " << arr[lb] << endl;
    } else {
        cout << "Lower Bound value not found in array." << endl;
    }
    return 0;
}
