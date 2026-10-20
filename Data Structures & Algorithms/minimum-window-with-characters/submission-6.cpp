class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return ""; 

        unordered_map<char,int> targetCounts;
        for(char& c : t){
            targetCounts[c]++;
        }

        unordered_map<char,int> stringCounts;
        string res = ""; 
        int l = 0; 
        int count = 0; 
        int minLength = s.size() + 1;
        int startIndex = 0; 
        for(int r = 0; r < s.size(); r++){
            if(targetCounts.contains(s[r])){
                stringCounts[s[r]]++; 
                if (stringCounts[s[r]] == targetCounts[s[r]]){
                    count++;
                }
            }

            while(count == targetCounts.size()){
                if(targetCounts.contains(s[l])){
                    if( 1+r-l < minLength){
                        minLength = 1+r-l;
                        startIndex = l; 
                    }

                    stringCounts[s[l]]--; 
                    if(stringCounts[s[l]] < targetCounts[s[l]]){
                        count--;
                    }
                }
                l++;
                }
        
        }
        return minLength > s.size() ? "" : s.substr(startIndex, minLength); 
    }
};
