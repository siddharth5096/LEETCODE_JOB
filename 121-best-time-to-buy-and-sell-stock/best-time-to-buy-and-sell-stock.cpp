class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int prof = 0;
    int temp = 0;
    int min_int = INT_MAX;
    for(int i = 0;i<prices.size();i++)
    {
        if(prices[i]<min_int)
            min_int = prices[i];
        else
        {
            temp = prices[i]-min_int;
            prof = max(prof,temp);
        }
    }   
    return prof;
    }
};