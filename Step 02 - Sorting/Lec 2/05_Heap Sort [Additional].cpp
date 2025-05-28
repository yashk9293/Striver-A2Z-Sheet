#include <iostream>
#include <vector>
using namespace std;

// Heapify a subtree rooted at index i in array of size n
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;          // Initialize largest as root
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    
    if (largest != i) {     // If largest is not root
        swap(arr[i], arr[largest]);
        
        heapify(arr, n, largest);  // Recursively heapify the affected sub-tree
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Build a maxheap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}
