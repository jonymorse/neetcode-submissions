class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        int maxArea = 0;
        while(l < r){
            int length = min(heights[l], heights[r]);
            int width = r - l;
            int area = width * length;

            if(heights[l] < heights[r]){
                l++;
            }  
            else if(heights[l] > heights[r]){
                r--;
            }
            else{
                l++;
                r--;
            }
            maxArea < area ? maxArea = area : maxArea = maxArea;
        }
        return maxArea;

    }
};
