class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> seen;
        for(string& s : strs){
            string w = s;
            sort(w.begin(), w.end());
            seen[w].push_back(s);
        }
        vector<vector<string>> res;

        for(auto& v : seen){
            res.push_back(v.second);
        }
        return res;
    }
};
