// Question Link :- https://leetcode.com/problems/implement-queue-using-stacks
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
    stack<int> s;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        if(s.size() == 0) {
            s.push(x);
            return;
        }
        int data;
        data = s.top();
        s.pop();
        push(x); // recursive call
        s.push(data);
        return;
    }
    
    int pop() {
        int temp = s.top();
        s.pop();
        return temp;
    }
    
    int peek() {
        return s.top();
    }
    
    bool empty() {
        return (s.size()==0);
    }
};
