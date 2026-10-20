class Solution {
public:
    int findDuplicate(vector<int>& nums) {
    int dup = 0; 
    vector<int> seen(nums.size(), 0);
    for(int n : nums){
        if(seen[n-1] != 0){
            return n;
        }
        else{
            seen[n-1] = n;
        }
    }
    return 0;
    }
};
