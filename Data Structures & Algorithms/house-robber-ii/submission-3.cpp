class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        return max( h(nums, 0, nums.size()-1), h(nums, 1, nums.size()));
    }
private:
    int h(vector<int>& nums, int n, int e){
        int prev2 = 0;
        int prev1 = 0; 
        for(int i = n; i < e; i++){
            int rob = nums[i] + prev2; 
            int skip = prev1; 
            int next = max(rob, skip);
            prev2 = prev1; 
            prev1 = next;
        }
        return prev1; 
    }
};
