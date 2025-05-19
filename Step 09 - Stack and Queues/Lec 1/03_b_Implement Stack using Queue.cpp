// Question Link :- https://leetcode.com/problems/implement-stack-using-queues/
// Implement Stack using Queues

// Using single queue
// T.C = O(N)
// S.C = O(N)
class MyStack {
public:
    queue<int> q;

    MyStack() {
        
    }

    void push(int x) {
        int s = q.size();
        q.push(x);
        for (int i = 0; i < s; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int n = q.front();
        q.pop();
        return n;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};