class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int bi = 0;
        int sell = 0;
        int profit = 0; 
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < buy){
                buy = prices[i];
                bi = i; 
            }
            if(i > bi){
                sell = prices[i];
                profit = max(profit, sell - buy);
            }

        }
        if(profit < 0) return 0;
        return profit;
    }
};
