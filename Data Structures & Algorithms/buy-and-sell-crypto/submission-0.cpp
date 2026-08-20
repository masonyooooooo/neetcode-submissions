class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int buy = 0;

        for (int sell = 1; sell < prices.size(); sell++) {
            int curr = prices[sell] - prices[buy];
            profit = max(profit, curr);
            if (prices[sell] < prices[buy])
                buy = sell;
        }

        return profit;
    }
};
