class Solution {
public:
    int rob(vector<int>& nums) {
        int prev2 = 0; 
        int prev1 = 0; 

        for(int i : nums){
            int next = max(i + prev2, prev1);
            prev2 = prev1; 
            prev1 = next; 
        }
        return prev1;
    }
};
