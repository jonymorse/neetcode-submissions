class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        dfs(nums, subset, res, 0);
        return res;
    }
private:
    void dfs(vector<int>& nums, vector<int>& subset, vector<vector<int>>& res, int index){
        res.push_back(subset);
        for(int i = index; i < nums.size(); i++){
            subset.push_back(nums[i]);
            dfs(nums,subset,res,i+1);
            subset.pop_back();
        }
        return; 
    }
};
