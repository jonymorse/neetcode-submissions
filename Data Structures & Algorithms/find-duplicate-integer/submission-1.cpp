class Solution {
public:
    int findDuplicate(vector<int>& nums) {
    int dup = 0; 
    sort(nums.begin(), nums.end());
    for(int n : nums){
        if(n == dup){
            return dup;
        }
        dup = n;
    }
    return 0;
    }
};
