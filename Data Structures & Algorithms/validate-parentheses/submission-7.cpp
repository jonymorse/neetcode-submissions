class Solution {
public:
    bool isValid(string s) {
    stack<char> st; 
    unordered_map<char,char> hm;
    hm['['] = ']';
    hm['('] = ')';
    hm['{'] = '}';

    for(char c : s){
        if(!st.empty()){
            if(c == hm[st.top()]){
                st.pop();
            }
            else{
                st.push(c);
            }
        }
        else{
            st.push(c);
        }
    }
    if(!st.empty()){
        return false;
    }
    return true;   
    }
};
