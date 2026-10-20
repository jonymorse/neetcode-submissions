class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> seen; 
        int l = 0; 
        int res = 0; 
        int maxFreq = 0; 
        int kl = 0; 
        for(int r = 0; r < s.size(); r++){
            char c = s[r];
            int window = 1 + r-l; 
            seen[c] ++;
            maxFreq = max(maxFreq, seen[c]); 
            if(window - maxFreq > k){
                seen[s[l]]--;
                l++;
            }
            else{
                res = max(res, window); 

            }
       
        }
        return res; 
    }
};
