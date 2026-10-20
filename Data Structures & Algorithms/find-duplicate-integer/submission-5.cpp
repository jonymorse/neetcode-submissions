class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int slow = 0;
        int fast = 0;
        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];

            if(slow == fast){
                break;
            }
        }

        return slow;
    }
};
