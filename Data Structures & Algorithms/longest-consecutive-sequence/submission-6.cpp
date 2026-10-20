class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.empty()){
            return 0;
        }

        unordered_set<int> unique;
        for(int element : nums){
            unique.insert(element);
        }
        unordered_set<int> seq;

        int best = 0;

        for(auto& k : unique){
            
            if(!unique.count(k - 1)){
                int cur = k; 
                int len = 1;

                while( unique.count(cur+1) ){
                    len++;
                    cur++;
                }
                best = max(best, len);
            }

            
        }
        return best;
    }
};
