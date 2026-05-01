class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int profit = INT_MIN;
    int  minNum = INT_MAX;
    for(int i=0;i<prices.size();i++)
    {
        minNum = min(minNum,prices[i]);
        profit = max(profit,prices[i]-minNum);
    }

    return profit;
    }
};