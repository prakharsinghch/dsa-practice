class MyStack {
public:
    vector<int> v;
    MyStack() {
        
    }
    
    void push(int x) {
        v.push_back(x);
        
    }
    
    int pop() {
        int n = v [ v.size() -1];
        v.resize(v.size()-1);
        return n;
        
    }
    
    int top() {
        return v[v.size() -1];
    }
    
    bool empty() {
        if(v.size()) return false;
        else return true;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */