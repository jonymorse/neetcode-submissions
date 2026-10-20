class Solution {
public:
    unordered_map<char,unordered_set<char>> graph;
    unordered_map<char,int> incoming; 
    string foreignDictionary(vector<string>& words) {
        for(auto& word : words){
            for(auto& ch : word){
                graph[ch];
                incoming[ch]; 
            }
        }

        string res = "";
        for(int i = 0; i + 1< words.size(); i++){
            string word1 = words[i];
            string word2 = words[i+1]; 
            if(!compare(word1,word2)) return res;
        }

        queue<char> q; 

        for(auto& n : incoming){
            if(n.second == 0) q.push(n.first);
        }

        while(!q.empty()){
            
            for(auto& child : graph[q.front()]){

                if(incoming[child] == 1){
                    q.push(child);
                }
                incoming[child]--;
            }
            if(incoming[q.front()] == 0){
                res += q.front();

                q.pop();
            }
        }
        if(res.size() < graph.size()) return "";
        return res; 
    }


private: 
    bool compare(string& word1, string& word2){
        int mz = min(word1.size(), word2.size()); 
        for(int i = 0; i < mz; i++){
            if(graph[word1[i]].contains(word2[i])) return true;
            if(word1[i] != word2[i]){
                graph[word1[i]].insert(word2[i]);
                incoming[word2[i]]++; 
                return true;
            }
        }
        if(word1.size() > word2.size()) return false; 
        return true; 
    }
};
