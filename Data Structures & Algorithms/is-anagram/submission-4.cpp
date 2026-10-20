class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        int seen[26] = {0};

        for(int i = 0; i < s.size(); i++){
            seen[s[i] - 'a']++;
            seen[t[i] - 'a']--;
        }
        for(auto n : seen){
            if(n < 0) return false;
        }
        return true;

    }
};
