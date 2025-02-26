class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
    int maxSum = INT_MIN;
    int minSum = INT_MAX;
    int preSum = 0;
    int negSum = 0;
    for(int i=0;i<nums.size();i++)
    {
        preSum += nums[i];
        maxSum = max(maxSum,preSum);
        if(preSum<0)
        {
            preSum=0;
        }
    }  

    for(int i=0;i<nums.size();i++)
    {
        negSum += nums[i];
        minSum = min(minSum,negSum);
        if(negSum>0)
        {
            negSum = 0;
        }
    }

    return max(maxSum,abs(minSum));
    }
};