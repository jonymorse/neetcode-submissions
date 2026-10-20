class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int prev2 = 0; 
        int prev1 = 0;
        
        for(int i = 0; i < nums.size()- 1; i++){
            int rob = nums[i] + prev2; 
            int skip = prev1; 

            int next = max(rob, skip); 
            prev2 = prev1; 
            prev1 = next;
        }
        int ans1 = prev1; 
        prev1 = 0, prev2 = 0;
        for(int i = 1; i < nums.size(); i++){
            int rob = nums[i] + prev2; 
            int skip = prev1; 

            int next = max(rob, skip); 
            prev2 = prev1; 
            prev1 = next;
        }
        return max(prev1,ans1);
    }
};
