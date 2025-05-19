// Question Link :- https://leetcode.com/problems/implement-queue-using-stacks/
// Implement Queue using Stacks

/* T.C :
Enqueue (push): O(n)
Dequeue (pop): O(1)
Peek (peek): O(1)
Empty Check (empty): O(1)
(where n is the number of elements in the queue.) */

// S.C = O(n)

class MyQueue {
private:
    stack<int> s1;
    stack<int> s2;

public:
    MyQueue() {}

    void push(int x) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop() {
        int temp = s1.top();
        s1.pop();
        return temp;
    }

    int peek() {
        return s1.top();
    }

    bool empty() {
        return s1.empty();
    }
};

