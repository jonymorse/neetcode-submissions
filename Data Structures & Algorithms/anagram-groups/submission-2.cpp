class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

    unordered_map<string, vector<string>> anagrams;
    vector<vector<string>> anagramsList;

    for(auto& s : strs){
        string word = s;
        sort(s.begin(), s.end());
        anagrams[s].push_back(word);
    }    
    for(auto& kv : anagrams){
        anagramsList.push_back(kv.second);
    }
    return anagramsList;
    }
};
