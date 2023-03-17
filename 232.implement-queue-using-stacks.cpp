/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

// @lc code=start
class MyQueue {
public:
    stack<int> st, st2;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(st.size()){
            st2.push(st.top());
            st.pop();
        }
        st.push(x);
        while(st2.size()){
            st.push(st2.top());
            st2.pop();
        }
    }
    
    int pop() {
        int ret = st.top();
        st.pop();
        return ret;
    }
    
    int peek() {
        return st.top();
    }
    
    bool empty() {
        return st.size() == 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

