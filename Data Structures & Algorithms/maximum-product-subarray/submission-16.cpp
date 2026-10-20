class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int min_prev = 1;
        int max_prev = 1; 
        int res = INT_MIN; 

        for(int i = 0 ; i < nums.size(); i++){
            int curr = nums[i];
            max_prev *= curr;
            min_prev *= curr;
            int m = min_prev; 
            min_prev = min(curr, min(max_prev, min_prev));
            max_prev = max(curr, max(max_prev, m));
            res = max(res, max_prev);
        }
        return res;
    }
};
