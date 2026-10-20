class Solution {
public:
    int search(vector<int>& nums, int target) {
    
    for(int i = 0; i < nums.size(); i++){
        int front = i;
        int back = nums.size() - 1;
        if(nums[front] == target){
            return front;
        }
        else if(nums[back] == target){
            return back;
        }
    }

    return -1;
    }
};
