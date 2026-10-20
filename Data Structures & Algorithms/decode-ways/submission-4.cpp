class Solution {
public:
    
    unordered_set<int> valid; 
    int numDecodings(string s) {
        for(int i = 1; i <= 26; i++){
            valid.insert(i);
        }
        return dfs(s,0);
    
    }
private:
    unordered_map<int,int> memo; 
    int dfs(string& s, int index){
        if(memo.contains(index)) return memo[index]; 
        if(index == s.size()){
            return 1; 
        }
        if(s[index] == '0') return 0; 

        int ways = dfs(s, index + 1); 
        if(index + 1 < s.size()){
            int num = ((s[index] - 48) * 10) + (s[index+1] - 48);
            if(s[index] != 0 && valid.contains(num)){
                ways += dfs(s, index + 2);
            }
        }
        memo[index] = ways;
        
        return ways; 
    }
};
