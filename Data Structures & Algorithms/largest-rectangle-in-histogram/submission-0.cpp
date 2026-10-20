class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
    stack<int> st; 
    heights.push_back(0);
    int area = 0;
    for(int i = 0; i < heights.size(); i++){
        int height = heights[i]; 
        int width = 0; 
        while(!st.empty() && height < heights[st.top()]){
        
                int m = st.top();
                st.pop();
                if(st.empty()){
                    width = i;
                }
                else{
                    width = i - st.top() - 1;
                }
                area = max(area, heights[m] * width);
        }

        st.push(i);
        area = max(area, height * (i - st.top() +1));
    }

    return area;
    }
};
