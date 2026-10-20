class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
    unordered_set<int> seen;
    seen.reserve(nums.size());
    
    for(auto elements : nums){
        auto result = seen.insert(elements);
        bool inserted = result.second;
        if (!inserted){
            return true;
        } 
    }
    return false;       
    }
};