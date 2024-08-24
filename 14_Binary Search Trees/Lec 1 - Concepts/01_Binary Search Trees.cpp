// Question Link :- https://www.geeksforgeeks.org/problems/binary-search-trees/1
// Binary Search Trees

// We know that the inorder traversal of binary search tree comes in ascending order so we are 
// checking whether the given input array elements are arranged in ascending order. If then return
// true else return false

// T.C = O(N)
// S.C = O(1)
class Solution {
  public:
    bool isBSTTraversal(vector<int>& arr) {
        for(int i=1; i<arr.size(); i++) {
            if(arr[i-1] >= arr[i])
                return false;
        }
        return true;
    }
};
