class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prev = 1; 
        int max_prev = 1; 
        int min_prev = -1; 
        int res = INT_MIN; 

        for(int i = 0 ; i < nums.size(); i++){
            int curr = nums[i];
            max_prev *= curr; 
            
            if(prev*curr > curr){
                prev *= curr;
            }
            else{
                prev = curr; 
            }
            if(max_prev > prev){
                prev = max_prev; 
                max_prev = curr;
            }
            

            res = max(res, prev); 
        }
        return res;
    }
};
