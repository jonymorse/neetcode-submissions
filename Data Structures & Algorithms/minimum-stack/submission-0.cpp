class MinStack {

private:
    vector<int> stack;
    vector<int> min; 

public:
    MinStack() {

    }
    
    void push(int val) {
        stack.push_back(val);

        if(!min.empty()){ // if min vector is not empty
            int prevMin = min[min.size() - 1];
            if(val < prevMin){ // if val < prevMin; 
                min.push_back(val);
            }
            else{
                min.push_back(prevMin);
            }
        }
        else{
            min.push_back(val);
        }

    }
    
    void pop() {
        min.pop_back();
        stack.pop_back();
    }
    
    int top() {
        return stack[stack.size() - 1];   
    }
    
    int getMin() {
        return min.back();
    }
};
