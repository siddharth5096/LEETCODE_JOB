class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>>ans;
    recursion(nums,ans,0);
    return ans;    
    }

    void recursion(vector<int>& nums,vector<vector<int>>&ans,int index)
    {
        if(index == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int i = index ; i<nums.size();i++)
        {
            swap(nums[i],nums[index]);
            recursion(nums,ans,index + 1);
            swap(nums[i],nums[index]);
        }
    }
};