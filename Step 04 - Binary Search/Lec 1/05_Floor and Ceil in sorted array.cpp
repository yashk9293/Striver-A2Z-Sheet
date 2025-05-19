#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int>& nums, int x) {
    int n = nums.size();
	int low = 0, high = n - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (nums[mid] >= x) {
			high = mid - 1;
		} else {
		    low = mid + 1;
		}
	}
	return low;
}

int main() {
	vector<int> nums{3, 4, 4, 7, 8, 10};
	int x = 5;
	int ceil_ = lowerBound(nums, x);
	
	if(ceil_ == nums.size()) {
	    cout << "Ceil = -1" << endl;
	} else {
	    cout << "Ceil = " << nums[ceil_] << endl;
	}
	
	if (ceil_ == 0) {
        cout << "Floor = -1" << endl;
    } else if (ceil_ < nums.size() && nums[ceil_] == x) {
        cout << "Floor = " << nums[ceil_] << endl;
    } else {
        cout << "Floor = " << nums[ceil_ - 1] << endl;
    }
	
	
	return 0;
}