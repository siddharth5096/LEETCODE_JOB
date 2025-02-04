class Solution {
private:
    int findLCS(string& s, string& t) {
        int n = s.size(), m = t.size();
        vector<int> prev(m+1,0);
        vector<int> curr(m+1,0);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i-1] == t[j-1]) {
                    curr[j] = 1 + prev[j-1];
                }
                else {
                    curr[j] = max(prev[j],curr[j-1]);
                }
            }
            prev = curr;
        }
        return prev[m];
    }
public:
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(s.begin(),s.end());
        return findLCS(s,t);
    }
};