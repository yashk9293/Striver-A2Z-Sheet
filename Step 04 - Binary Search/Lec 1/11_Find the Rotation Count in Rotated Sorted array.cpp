// Question Link :- https://www.geeksforgeeks.org/problems/rotation4723/1
// Rotation (same as Leetcode 153) [02]

// T.C = O(logN)
// S.C = O(1)
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    int l = 0, r = n-1;
	    while(l < r) {
	        int mid = l + (r-l)/2;
	        if(arr[mid] > arr[r]) {
	            l = mid+1;
	        } else {
	            r = mid;
	        }
	    }
	    return r;   // or return l
	}
};