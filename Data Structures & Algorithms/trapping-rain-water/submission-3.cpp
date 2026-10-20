class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int trap = 0;
        int leftMax = height[l];
        int rightMax = height[r];
        while(l < r){
            if(leftMax < rightMax){
                leftMax = max(leftMax, height[l+1]);
                trap += leftMax - height[l+1];
                l++;
            }
            else{
                rightMax = max(rightMax, height[r-1]);
                trap += rightMax - height[r-1];
                r--;
            }
        }
        return trap;         
    }
};
