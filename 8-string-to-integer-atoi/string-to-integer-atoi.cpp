class Solution {
public:
    int myAtoi(string s) {
        int ans = 0;
        int i = 0;
        int sign = 1;
        int max_int = INT_MAX;
        int min_int = INT_MIN;
        
        if (s.length() == 0) {
            return 0;
        }
        
        // Remove leading whitespaces
        while (i < s.length() && s[i] == ' ') {
            i++;
        }
        
        // Check for sign
        if (i < s.length() && (s[i] == '-' || s[i] == '+')) {
            if (s[i] == '-') {
                sign = -1;
            }
            i++;
        }
        
        // Convert digits to integer
        while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
            int digit = s[i] - '0';
            if (ans > max_int / 10 || (ans == max_int / 10 && digit > max_int % 10)) {
                return (sign == 1) ? max_int : min_int;
            }
            ans = ans * 10 + digit;
            i++;
        }
        
        return ans * sign;
    }
};