class Solution {
public:
    int f(int i, int j, int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore, vector<vector<int>> &dp)
    {
        if(i>=n || j>k-1) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int stay = stayScore[j][i] + f(i,j+1,n,k,stayScore,travelScore,dp);
        int move = 0;
        for(int m=0; m<n; m++)
        {
            move = max(move, travelScore[i][m] + f(m,j+1,n,k,stayScore,travelScore,dp));
        }

        return dp[i][j] = max(move,stay);

    }
    int maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
        int ans = 0;
        vector<vector<int>> dp(n,vector<int>(k,-1));
        for(int i=0; i<n; i++)
        {
            ans = max(ans,f(i,0,n,k,stayScore,travelScore,dp));
        }

        return ans;
    }
};