// Question Link - https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
// Length of the largest subarray with sum 0

// Brute Force
// T.C = O(n^3)
// S.C = O(1)
class Solution {
  public:
    int maxLen(vector<int>& arr) {
        int n = arr.size();
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int sum = 0;
                for (int k = i; k <= j; k++) {
                    sum += arr[k];
                }
                if (sum == 0) {
                    maxi = max(maxi, j - i + 1);
                }
            }
        }
        return maxi;
    }
};



// Better Approach
// T.C = O(n^2)
// S.C = O(1)
class Solution {
  public:
    int maxLen(vector<int>& arr) {
        int n = arr.size();
        int maxi = 0;
        
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += arr[j];
                if (sum == 0) {
                    maxi = max(maxi, j - i + 1);
                }
            }
        }
        return maxi;
    }
};




// T.C = O(N)
// S.C = O(N)
class Solution {
  public:
    int maxLen(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> mpp; 
        int maxi = 0;
        int sum = 0; 
        for(int i=0; i<n; i++) {
            sum += arr[i]; 
            if(sum == 0) {
                maxi = i + 1; 
            }
            if(mpp.find(sum) != mpp.end()) {
                maxi = max(maxi, i - mpp[sum]); 
            }
            else {
                mpp[sum] = i;
            }
        }
        return maxi;
    }
};