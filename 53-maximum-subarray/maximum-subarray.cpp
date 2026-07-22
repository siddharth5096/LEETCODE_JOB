class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int temp = 0;
        int maxSum = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            temp += nums[i];
            maxSum = max(maxSum, temp);

            if (temp < 0) {
                temp = 0;
            }
        }

        return maxSum;
    }
};