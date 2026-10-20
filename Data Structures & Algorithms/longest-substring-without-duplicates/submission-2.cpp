class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> seen; 
        int count = 0; 
        int longest = 0; 
        for(int i = 0; i < s.size(); i++){
            char c = s[i]; 
            if(seen.contains(c)){
                longest = max(count, longest);
                count = 0;
                i = seen[c]; 
                seen.clear();
                continue;
            }
            seen[c] = i; 
            count++; 
        }
        return max(longest, count); 
    }
};
