class Solution {
public:
    int divide(int dividend, int divisor) {
         long a;
        a=(long)dividend/divisor;
        if(a >= INT_MAX)
       return INT_MAX;
        else if(a <= INT_MIN)
        return INT_MIN;
        else
         return (int)a;
    }
};