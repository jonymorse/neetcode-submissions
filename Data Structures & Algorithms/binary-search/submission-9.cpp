class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0; 
        int r = nums.size() - 1; 
        while(l <= r){
            if(nums[l] == target) return l;
            if(nums[r] == target) return r;
            l++;
            r--;
        }
        return -1;
    }
};
