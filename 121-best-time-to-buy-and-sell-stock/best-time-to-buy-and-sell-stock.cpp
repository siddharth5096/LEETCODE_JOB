class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int prof = 0;
    int min_int = INT_MAX;
    for(int i = 0;i<prices.size();i++)
    {
        min_int = min(min_int,prices[i]);
        prof = max(prof,prices[i]-min_int);
    }   
    return prof;
    }
};