class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int l = 0; 
        int res = 0; 
        for(int r = 0; r < s.size(); r++){
            
            while(seen.contains(s[r])){
                //l++; 
                seen.erase(s[l]); 
                l++;
            }
            res = max(res, 1+r-l);
            seen.insert(s[r]);
        }
        return res;
    }
};
