class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        /*

        */  
        stack<double> st; 
        vector<pair<int,int>> vec;
        for(int i = 0; i < position.size(); i++){
            pair<int, int> p = {position[i], speed[i]};
            vec.push_back(p);
        }   
        sort(vec.rbegin(), vec.rend());

        int count = 0;

        for(auto& n : vec){
            double time = (double) (target - n.first) / n.second;
            if(st.empty()){
                count++;
                st.push(time);
            }
            else if(time > st.top()){
                count++;
                st.pop();
                st.push(time);
            }
        }

        return count;
    }
};
