/*
 * @see https://leetcode.com/problems/implement-queue-using-stacks
 * 
 * 用双栈实现队列
 */
#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
public:
    stack<int> s;

    /** Push element x to the back of queue. */
    void push(int x) {
        stack<int> tmp;
        while (!s.empty()) {
            tmp.push(s.top());
            s.pop();
        }
        s.push(x);
        while (!tmp.empty()) {
            s.push(tmp.top());
            tmp.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int top = s.top();
        s.pop();
        return top;
    }
    
    /** Get the front element. */
    int peek() {
        return s.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s.empty();
    }
};

/**
 * Amortized O(1).
 *
class MyQueue {
public:
    stack<int> input, output;
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        int top = peek();
        output.pop();
        return top;
    }
    
    int peek() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }
    
    bool empty() {
        return input.empty() && output.empty();
    }
};
 */

int main()
{
    MyQueue myQueue;
    myQueue.push(1); // queue is: [1]
    myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
    cout << myQueue.peek() << endl; // return 1
    cout << myQueue.pop() << endl; // return 1, queue is [2]
    cout << myQueue.empty() << endl; // return false

    return 0;
}
