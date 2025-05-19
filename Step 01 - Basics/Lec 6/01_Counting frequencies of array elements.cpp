// Question Link :- https://www.geeksforgeeks.org/problems/frequency-of-array-elements-1587115620/0
// Frequencies in a Limited Array

// T.C = O(N)
// S.C = O(1)
class Solution {
    public:
      vector<int> frequencyCount(vector<int>& arr) {
          int n = arr.size();
          vector<int> freq(n, 0);
          for(int i=0; i<n; i++) {
              freq[arr[i]-1]++;
          }
          return freq;
      }
  };