class Solution {
public:
    int maxScore(string s) {
        int ones = count(s.begin(), s.end(), '1');
        int zeros = 0, maxScore = 0;
        
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == '0') zeros++;
            else ones--;
            maxScore = max(maxScore, zeros + ones);
        }
        
        return maxScore;
    }
};