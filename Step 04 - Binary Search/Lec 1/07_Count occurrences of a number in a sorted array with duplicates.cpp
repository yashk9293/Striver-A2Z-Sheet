// Question Link :- https://www.naukri.com/code360/problems/occurrence-of-x-in-a-sorted-array_630456
// Count occurrences in a sorted array with duplicates


// T.C = O(n)
// S.C = O(1)
int count(vector<int>& arr, int n, int x) {
	int cnt = 0;
    for (int i=0; i<n; i++) {
        if (arr[i] == x) {
			cnt++;
		}
    }
    return cnt;
}




// T.C = O(log n)
// S.C = O(1)
int firstOcc(vector<int>& arr, int n, int x) {
    int first = -1;
    int l=0, h=n-1;
    while(l <= h) {
        int mid = l+(h-l)/2;
        if(arr[mid] == x) {
            first = mid;
            h = mid-1;
        }
        else if(arr[mid] < x) {
            l = mid + 1;
        } else {
            h = mid - 1;
        }
    }
    return first;
}

int lastOcc(vector<int>& arr, int n, int x) {
    int last = -1;
    int l=0, h=n-1;
    while(l <= h) {
        int mid = l+(h-l)/2;
        if(arr[mid] == x) {
            last = mid;
            l = mid+1;
        }
        else if(arr[mid] < x) {
            l = mid + 1;
        } else {
            h = mid - 1;
        }
    }
    return last;
}

int count(vector<int>& arr, int n, int x) {
    int first = firstOcc(arr, n, x);
    if(first == -1) {
        return 0;
    }

    int last = lastOcc(arr, n, x);

    return last - first + 1;
}
