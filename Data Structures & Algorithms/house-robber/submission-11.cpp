class Solution {
public:
    int rob(vector<int>& nums) {
        int prev2 = 0; 
        int prev1 = 0; 

        for(int i : nums){
            int rob = i + prev2;
            int skip = prev1; 
            int next = max(rob, skip);
            prev2 = prev1; 
            prev1 = next; 
        }
        return prev1;
    }
};
