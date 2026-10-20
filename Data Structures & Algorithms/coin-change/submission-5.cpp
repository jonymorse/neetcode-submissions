class Solution {
public:
    
    unordered_map<int,int> minCoins; 
    int coinChange(vector<int>& coins, int amount) {
        return dfs(coins, amount); 
    }

private: 
    int dfs(vector<int>& coins, int amount){
        if(amount < 0) return -1; 
        if(amount == 0) return 0; 
        if(minCoins.contains(amount)) return minCoins[amount]; 

        int minAmount = amount + 1; 

        for(int i = 0; i < coins.size(); i++){
            int change = amount - coins[i]; 
            int numOfCoins = dfs(coins, change);
            minCoins[change] = numOfCoins;
            if(numOfCoins != -1) minAmount = min(numOfCoins+1, minAmount); 
 
        }

        return minAmount == amount + 1 ? -1 : minAmount; 
    }
};
