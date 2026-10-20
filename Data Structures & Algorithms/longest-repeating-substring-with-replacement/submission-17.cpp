class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> seen; 
        int res = 0;
        int maxFreq = 0;
        int l = 0; 
        int window = 0; 
        for(int r = 0; r < s.size(); r++){

            seen[s[r]]++;
            window = 1+r-l;
            maxFreq = max(maxFreq, seen[s[r]]);
            while(window - maxFreq > k){
                seen[s[l]]--;
                l++;
                window = 1+r-l;
                
            }
            res = max(res, window); 
        }

        return res;
    }
};
