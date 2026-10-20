class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        make_heap(nums.begin(), nums.end());
        while(k > 1){
            k--;
            pop_heap(nums.begin(), nums.end());
            nums.pop_back();
        }
        pop_heap(nums.begin(), nums.end());
        return nums.back();
    }
};
