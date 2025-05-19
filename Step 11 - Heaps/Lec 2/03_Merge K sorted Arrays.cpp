// Question Link :- https://www.geeksforgeeks.org/problems/merge-k-sorted-arrays/1
// Merge k Sorted Arrays


class Solution {
    public:
    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
        vector<int> ans;
        
        // create a min-heap
        priority_queue<int, vector<int> , greater<int>> pq;
        for(int i= 0; i < arr.size(); i++) {
            for(int j = 0; j < K; j++) {
                // push all the elements to the priority-queue -> which takes O(log(pq.size())) for each element
                pq.push(arr[i][j]);
            }
        }
        
        // remove the elements from pq and put into ans vector -> which takes O(k^2)
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};