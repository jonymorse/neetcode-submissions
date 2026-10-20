class Solution {
public:
    unordered_map<int,int> memo; 
    int dfs(vector<int>& nums, int index, int prev){ 
        if(index == nums.size()) return 0;  
        if(memo.contains(index)) return memo[index];
        int len; 
        int res = 0; 
        for(int i = index; i < nums.size(); i++){
            int curr = nums[i];
            len = 0;
            if(curr > prev){
                len++; 
                len += dfs(nums, i+1, curr);
            }
            res = max(res, len);
        }
        memo[index] = res; 
        return res;


    }
    int lengthOfLIS(vector<int>& nums) {
        return dfs(nums, 0, INT_MIN);
    }
};
