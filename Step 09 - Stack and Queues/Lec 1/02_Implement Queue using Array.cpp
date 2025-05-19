// IMPLEMENTATION OF QUEUE USING ARRAY
// Question Link :- https://www.codingninjas.com/studio/problems/queue-using-array-or-singly-linked-list_2099908
// Implement a Queue

// T.C = O(1)
// S.C = O(1)
#include <bits/stdc++.h> 
class Queue {
    int *arr;
    int qfront;
    int rear;
    int size;
public:
    Queue() {
        size = 100001;
        arr = new int[size];
        qfront=0;
        rear=0;
    }

    bool isEmpty() {
        if(qfront == rear) {
            return true;
        }
        return false;
    }

    void enqueue(int data) {
        if(rear == size) {
            return;
        }
        arr[rear] = data;
        rear++;
    }

    int dequeue() {
        if(isEmpty()) {
            return -1;
        }
        int ans = arr[qfront];
        arr[qfront] = -1;
        qfront++;
        if(qfront == rear) {
            qfront = 0;
            rear = 0;
        }
        return ans;
    }

    int front() {
        if(isEmpty()) {
            return -1;
        }
        return arr[qfront];
    }
};