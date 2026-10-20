class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string s : tokens){
            if(s == "+"){
                int a = st.top();
                st.pop();
                a += st.top();
                st.pop();
                st.push(a);
            }
            else if(s == "-"){
                int s = st.top();
                st.pop();
                s = st.top() - s;
                st.pop();
                st.push(s);
            }
            else if(s == "*"){
                int m = st.top();
                st.pop();
                m *= st.top();
                st.pop();
                st.push(m);
            }
            else if(s == "/"){
                int d = st.top();
                st.pop();
                d = st.top() / d;
                st.pop();
                st.push(d);
            }
            else{
                int num = stoi(s);
                st.push(num);
            }
        }
        return st.top();
    }
};
