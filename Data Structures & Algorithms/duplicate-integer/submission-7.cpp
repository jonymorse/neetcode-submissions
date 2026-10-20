class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
    unordered_set<int> seen;
    seen.reserve(nums.size());
    
    for(int x : nums){
        
        if (!seen.insert(x).second){
            return true;
        }
    }
    return false;       
    }
};