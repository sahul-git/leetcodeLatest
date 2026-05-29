class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1 = INT_MIN;
        int buy2 = INT_MIN;
        int sell1 = 0;
        int sell2 = 0;
        for(int i=0; i<prices.size(); i++){
            buy1 = max(-prices[i], buy1);
            sell1 = max(buy1 + prices[i], sell1);
            buy2 = max(sell1 - prices[i], buy2);
            sell2 = max(buy2 + prices[i], sell2);
        }
        return sell2;

    }
};