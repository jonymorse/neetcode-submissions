class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int val = 0;
        int mx = 0;  
        unordered_set<int> seen; 
        seen.insert(-1);
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            mx = max(mx, nums[i]);
            if(!seen.contains(nums[i] -1)){
                val = nums[i] - 1; 
            }
            seen.insert(nums[i]);
        }

        if(val == 0 && seen.contains(0)) return mx+1;
        return val; 
    }
};
