class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        array<int, 26> seen = {};
        for(size_t i = 0; i < s.size(); i++){
            seen[s[i] - 'a']++;
            seen[t[i] - 'a']--;
        }
        for(auto i : seen){
            if(i < 0) return false;
        }

        return true;
    }
};
