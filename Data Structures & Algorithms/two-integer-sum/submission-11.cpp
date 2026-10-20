class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

     unordered_map<int, int> indexMap;
     vector<int> twoSum; 
     for(int i = 0; i < nums.size(); i++){
        int element = nums[i];
        int comp = target - element;

        if( indexMap.find(comp) != indexMap.end() && indexMap[comp] != i){
            int compIndex = indexMap[comp];
            twoSum.push_back(compIndex);
            twoSum.push_back(i);
        }
        indexMap[element] = i; // we add the elemet and its index

     }   
     sort(twoSum.begin(), twoSum.end());
     return twoSum;
    }
};
