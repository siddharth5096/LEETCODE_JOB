#include <vector>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int overallSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            overallSum += nums[i];
        }

        // If the overall sum is odd, it cannot be split into two equal subsets.
        if (overallSum % 2 != 0) {
            return false;
        }

        // Target sum for each subset.
        int target = overallSum / 2;

        // Call helper function to determine if subset sum equals target.
        return helper(nums, target, nums.size());
    }

private:
    bool helper(vector<int>& nums, int target, int n) {
        // Create a DP table initialized to false.
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

        // Base case: A sum of 0 is always possible (empty subset).
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        // Fill the DP table.
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                if (nums[i - 1] <= j) {
                    // Include the current number or exclude it.
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                } else {
                    // Exclude the current number.
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        // The answer is in dp[n][target].
        return dp[n][target];
    }
};
