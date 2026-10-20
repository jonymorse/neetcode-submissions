class Solution {
public:
    map<int, int> memo; 
    int rob(vector<int>& nums) {
        return dfs(nums, 0);
    }
private:
    int dfs(vector<int>& nums, int i){
        if(i >= nums.size()) return 0;
        
        if(memo.contains(i)) return memo[i]; 
    

        int a = nums[i] + dfs(nums,i + 2); 
        int b =  dfs(nums, i + 1); 
        return memo[i] = max(a,b);
    }
};
