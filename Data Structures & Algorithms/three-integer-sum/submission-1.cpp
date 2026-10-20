class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> threeSum;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            int l = i + 1;
            int r = nums.size() - 1;
            int cur = nums[i];
            if(i > 0 && cur == nums[i-1]){
                continue;
            }
            while(l < r){
                int left = nums[l];
                int right = nums[r];
                int sum = cur + left + right;
                if(sum < 0){
                    l++;
                }
                else if(sum > 0){
                    r--;
                }
                else{
                    threeSum.push_back({left, cur, right});
                    l++;
                    while(l < r && nums[l] == nums[l-1]){
                        l++;
                    }
                    r--;
                    while(l < r && nums[r] == nums[r+1]){
                        r--;
                    }
                }

            }
        }
        return threeSum;
    }
};
