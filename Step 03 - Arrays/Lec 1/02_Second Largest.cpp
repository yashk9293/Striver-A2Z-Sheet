// Question Link :- https://www.geeksforgeeks.org/problems/second-largest3735/1
// Second Largest

// Brute Force
// T.C = O(nlogn) + O(n) = O(nlogn)
// S.C = O(1)
class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int largest = arr[n-1];
       // for test case like 1 2 4 5 7 7, second largest will be 5 not 7
        for(int i=n-2; i>=0; i--) {
            if(arr[i] != largest) {
                return arr[i];  // second largest
            }
        }
        return -1;
    }
};



// Better Approach
// T.C = O(n + n) = O(2n)
// S.C = O(1)
class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        int n = arr.size();
        int largest = INT_MIN;
        for(int i=0; i<n; i++) {
            if(arr[i] > largest) {
                largest = arr[i];
            }
        }
        int second_largest = INT_MIN;
        for(int i=0; i<n; i++) {
            if(arr[i] > second_largest && arr[i] != largest) {
                second_largest = arr[i];
            }
        }
        return second_largest == INT_MIN ? -1 : second_largest;
    }
};




// Optimal Solution
// T.C = O(n)
// S.C = O(1)
class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        int n = arr.size();
        int largest = INT_MIN, second_largest = INT_MIN;
        
        for (int i=0; i<n; i++) {
            if (arr[i] > largest) {
                second_largest = largest;  // if somethong is greater than largest than the current largest obviously become second largest
                largest = arr[i];
            } else if (arr[i] > second_largest && arr[i] != largest) {
                second_largest = arr[i];
            }
        }
        return second_largest == INT_MIN ? -1 : second_largest;
    }
};