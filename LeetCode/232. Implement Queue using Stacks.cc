class Queue {
public:

    stack<int> s1; 
    stack<int> s2;
    
    // Push element x to the back of queue.
    void push(int x) {
        s1.push(x);    
    }

    // Removes the element from in front of queue.
    void pop(void) {
        while(s1.empty() != true)
        {
            int top = s1.top();
            s2.push(top);
            s1.pop();
        }
        
        if(s2.empty() == false)
        {
            s2.pop();
        }
        
        while(s2.empty() != true)
        {
            int top = s2.top();
            s1.push(top);
            s2.pop();
        }
    }

    // Get the front element.
    int peek(void) {
        while(s1.empty() != true)
        {
            int top = s1.top();
            s2.push(top);
            s1.pop();
        }
        
        int top = -1;
        if(s2.empty() == false)
        {
            top = s2.top();
        }
        
        while(s2.empty() != true)
        {
            int top = s2.top();
            s1.push(top);
            s2.pop();
        }
        
        return top;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s1.empty();
    }
};