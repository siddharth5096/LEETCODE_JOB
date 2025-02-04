class Solution {
public:
int  f(int i, int a, vector<int> & coins, int &count,int n,vector<vector<int>> & dp ){
    if (a<0 || i>=n) return 0;
    if (a==0 ){
        
        return 1;
    }
    if (dp[i][a]!=-1) return dp[i][a];
    // take and not take condition
   int c= f(i+1, a, coins, count, n ,dp);
   int b= f(i, a-coins[i],coins, count, n,dp );
   return dp[i][a]=c+b;
}

    int change(int a, vector<int>& coins) {
        // yeah wala krde most probably mera backtracking aur recursion wala concept wala concept complete krna h 
        int i=0;
        int count=0;
        int n=coins.size();
        vector<vector<int>>dp ( n, vector<int> ( a+1, -1));
        return f(i,a, coins,count,n,dp );
        
    }
};