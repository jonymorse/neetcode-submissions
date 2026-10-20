class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN; 

        for(int i = 0; i < nums.size(); i++){
            res = max(res, dfs(nums, i));
        }
        return res; 
    }

private:
    int dfs(vector<int>& nums, int index){
        if(index == nums.size() - 1) return nums[index]; 


        return max(nums[index], nums[index] + dfs(nums, index+1));
    }
};
