class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int profit = 0;
        pair<int,int> minBuy = {prices[0], 0}; 
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < minBuy.first){
                minBuy = {prices[i], i};
            }
            if (prices[i] - minBuy.first > profit){
                profit = prices[i] - minBuy.first; 
            }

            
        }
        return profit;
    }
};
