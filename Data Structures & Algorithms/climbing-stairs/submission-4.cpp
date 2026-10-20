class Solution {
public:
    int climbStairs(int n) {

        int stairs = 1; 
        int prev = 0; 
        for(int i = 0; i < n; i++){
            stairs += prev; 
            prev = stairs - prev; 
        }   
        return stairs; 
    }
};
