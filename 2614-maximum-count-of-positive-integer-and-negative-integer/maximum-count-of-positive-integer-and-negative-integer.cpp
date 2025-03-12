class Solution {
public:
    int maximumCount(vector<int>& nums) {
    int posCnt = 0;
    int negCnt = 0;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]>0)
            posCnt++;
        else if(nums[i]<0)
            negCnt++;
    }    

    return max(posCnt,negCnt);
    }
};