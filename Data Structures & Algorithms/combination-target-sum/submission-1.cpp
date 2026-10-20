class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res; 
        vector<int> v; 
        int sum = 0;
        int start = 0; 
        dfs(res, nums, v, target, sum, start);
        return res;

    }
private:
    void dfs(vector<vector<int>>& res, vector<int>& nums, vector<int> v, int& target, int sum, int start ){

        for(int i = start; i < nums.size(); i++){
            v.push_back(nums[i]);
            
            if(nums[i] + sum == target){
                res.push_back(v);
            }
            else if (nums[i] + sum < target){
                dfs(res, nums, v, target, sum + nums[i], i);
            }

            v.pop_back();
        }
        return;
    }
};
