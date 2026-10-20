class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int left = 0;
        int res = 0; 

        for(int right = 0; right < s.size(); right++){
            char c = s[right]; 
            while(seen.contains(c)){
                seen.erase(s[left]);
                left++;
            }

            seen.insert(c);
            res = max(res, 1+ right-left) ;     
        }

        return res; 
    }
};
