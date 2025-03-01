class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
    vector<int>ans;
    int zeroCnt = 0;
    for(int i=0;i<nums.size()-1;i++)
    {
        if(nums[i] == nums[i+1])
        {
            nums[i] = nums[i] * 2;
            nums[i+1] = 0;
        }
    }
    int j=0;
    for(int i = 0;i<nums.size();i++)
    {
        if(nums[i]!=0)
        {
            nums[j] = nums[i];
            j++;
        }
    }
    fill(nums.begin()+j,nums.end(),0);
    return nums;
    }
};