class Solution {
public:
    unordered_map<char, unordered_set<char>> graph; 
    unordered_map<char,int> indegree; 
    
    string foreignDictionary(vector<string>& words) {

        for(auto& w : words){
            for(auto& c : w){
                graph[c]; 
                indegree[c];
            }
        }

        string res = "";
        for(int i = 0; i + 1 < words.size(); i++){
            string word1 = words[i];
            string word2 = words[i+1]; 
            if(compare(word1,word2) == false){
                return res; 
            }
            
        }

        queue<char> q; 
        for(auto& i : indegree){
            if(i.second == 0){
                q.push(i.first);
            }
        }

        while(!q.empty()){
            char curr = q.front();
            res += curr;
            for(auto& ch : graph[curr]){
                indegree[ch]--;
                if(indegree[ch] == 0){
                    q.push(ch);
                }
            }
            q.pop();
        }
        
        if(res.size() != graph.size()) return "";

        return res; 
    }

private:
    bool compare(string& word1, string& word2){
        int minsz = min(word1.size(), word2.size()); 
        for(int i = 0; i < minsz; i++){
            if(word1[i] == word2[i]) continue; 
            else if(word1[i] != word2[i]){
                if( !graph[word1[i]].contains(word2[i]) ){
                    graph[word1[i]].insert(word2[i]);
                    indegree[word2[i]]++; 
                }
                return true; 
            }

        }
        
        if(word1.size() > word2.size()) return false;
        return true;
    }
};
