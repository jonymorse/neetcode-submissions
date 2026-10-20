class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
    unordered_map<int, int> numberCountMap;
    for(auto& elements : nums){
        numberCountMap[elements]++;
        if (numberCountMap[elements] > 1){
            return true;
        }
    }
    return false;       
    }
};