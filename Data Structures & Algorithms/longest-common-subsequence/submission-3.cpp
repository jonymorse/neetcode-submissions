class Solution {
public:
    vector<vector<int>> memo;
    int longestCommonSubsequence(string text1, string text2) {
        memo.resize(text1.size(), vector<int>(text2.size(), -1));
        return dfs(text1, text2, 0,0);
    }
private:
    int dfs(string text1, string text2, int i1, int i2){
        if(i1 == text1.size() || i2 == text2.size()){
            return 0; 
        }
        if(memo[i1][i2] > -1) return memo[i1][i2]; 
        int same = 0;
        int adv1 = 0; 
        int adv2 = 0;
        int res = 0;  
        if(text1[i1] == text2[i2]){
            same += 1 + dfs(text1, text2, i1+1, i2+1);
        }
        else{
            adv1 = dfs(text1, text2, i1+1, i2);
            adv2 = dfs(text1, text2, i1, i2+1); 
            res = max(adv1, adv2); 
        }

        return memo[i1][i2] = max(same, res); 
        
    }
};
