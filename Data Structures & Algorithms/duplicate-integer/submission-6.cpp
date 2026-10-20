class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
    unordered_map<int, int> numberCountMap;
    numberCountMap.reserve(nums.size());
    
    for(int elements : nums){
        numberCountMap[elements]++;
        if (numberCountMap[elements] > 1){
            return true;
        }
    }
    return false;       
    }
};