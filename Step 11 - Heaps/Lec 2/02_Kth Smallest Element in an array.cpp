// Question Link :- https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1
// Kth Smallest Element in an array


// T.C = O(nlogk)
// S.C = O(k)
class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        priority_queue<int> pq;
        for(int i=0; i<arr.size(); i++) {
            pq.push(arr[i]);
            if(pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }
};