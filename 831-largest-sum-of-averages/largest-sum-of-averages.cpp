class Solution {
public:
    double solve(int i, int k, vector<int>& nums, vector<vector<double>>&dp) {
        if (i == nums.size()) return (k == 0) ? 0 : -1e9;
        if (k == 0) return -1e9;  

        if(dp[i][k] != -1) return dp[i][k];
        
        double sum = 0, maxAvg = -1e9;
        for (int j = i; j < nums.size(); j++) {
            sum += nums[j];
            maxAvg = max(maxAvg, (sum / (j - i + 1)) + solve(j + 1, k - 1, nums,dp));
        }
        return dp[i][k] = maxAvg;
    }

    double largestSumOfAverages(vector<int>& nums, int k) {
        vector<vector<double>> dp(nums.size(), vector<double>(k+1, -1));
        return solve(0, k, nums, dp);
    }
};