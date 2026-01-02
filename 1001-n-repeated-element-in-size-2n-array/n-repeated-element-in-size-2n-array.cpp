class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
    unordered_map<int, int>numsCnt;
    for(int i=0;i<nums.size();i++)
    {
        numsCnt[nums[i]]++;
        if (numsCnt[nums[i]] > 1) {
            return nums[i];
    }
    }
    return -1;
    }
};