class Solution {
public:
    int findDuplicate(vector<int>& nums) {
    int dup = 0; 
    unordered_set<int> seen;
    for(int n : nums){
        if(seen.find(n) != seen.end()){
            return n;
        }
        else{
            seen.insert(n);
        }
    }
    return 0;
    }
};
