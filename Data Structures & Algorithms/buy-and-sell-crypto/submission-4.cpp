class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int profit = 0;
        pair<int,int> minBuy = {prices[0], 0}; 
        pair<int,int> maxSell = {0, -1};
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < minBuy.first){
                minBuy = {prices[i], i};
            }
            if(i > 0 ){
               if (prices[i] - minBuy.first > profit){
                    profit = prices[i] - minBuy.first; 
                    maxSell = {prices[i], i};
                }
            }

            
        }
        return profit;
    }
};
