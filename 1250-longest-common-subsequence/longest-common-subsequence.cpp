class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int s1 = text1.size();
        int s2 = text2.size();
        vector<vector<int>> dp(s1+1, vector<int>(s2+1, -1));
        return helper(text1, text2, s1, s2, dp);
    }

    int helper(const string& text1, const string& text2, int s1, int s2, vector<vector<int>>& dp) {
        if (s1 == 0 || s2 == 0)
            return 0;

        if (dp[s1][s2] != -1)
            return dp[s1][s2];

        if (text1[s1-1] == text2[s2-1])
            return dp[s1][s2] = 1 + helper(text1, text2, s1-1, s2-1, dp);
        else
            return dp[s1][s2] = max(helper(text1, text2, s1-1, s2, dp), helper(text1, text2, s1, s2-1, dp));
    }
};
