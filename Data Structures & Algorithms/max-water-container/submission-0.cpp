class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        int max = 0;
        while(l < r){
            int w = r - l;
            int h = min(heights[l], heights[r]);   
            int area = w*h;
            if(heights[r] > heights[l]){
                l++;
            }
            else if(heights[l] > heights[r]){
                r--;
            }else{
                l++;
                r--;
            }
            max < area ? max = area : max = max;
        }
        return max;
    }
};
