// Question Link :- https://www.geeksforgeeks.org/problems/does-array-represent-heap4345/1
// Does array represent Heap

// T.C = O(n)
// S.C = O(1)
class Solution{
    public:
    bool isMaxHeap(int arr[], int n) {
        // for 0 based indexing left child = 2i+1 & right child = 2i+2
        // dont checkk for leaf nodes -- half of the array
        for(int i=0; i<n/2; i++) {
            if(arr[i] < arr[2*i+1] || arr[i] < arr[2*i+2]) {
                return false;
            }
        }
        return true;
    }
};