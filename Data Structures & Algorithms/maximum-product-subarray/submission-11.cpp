class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prev = 1; 
        int max_prev = 1; 
        int res = INT_MIN; 

        for(int i = 0 ; i < nums.size(); i++){
            max_prev *= nums[i]; 
            prev = prev*nums[i] > nums[i] ? prev*nums[i] : nums[i]; 

            if(max_prev > prev){
                prev = max_prev; 
                max_prev = nums[i];
            }
            res = max(res, prev); 
        }
        return res;
    }
};
