class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int currIndex = nums.size() - 2; 
        int goalIndex = nums.size() - 1;  
        while(currIndex >= 0){
            if(currIndex + nums[currIndex] >= goalIndex){
                goalIndex = currIndex;
            }
            currIndex--; 
        }

        return (goalIndex == 0); 
    }
};
