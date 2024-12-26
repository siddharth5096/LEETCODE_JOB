class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>>ans;
    vector<int>temp;
    recursive(nums,ans,temp,0);
    return ans;    
    }

    void recursive(vector<int>& nums,vector<vector<int>>& ans,vector<int>&temp,int i)
    {
        if(i == nums.size())
        {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        recursive(nums,ans,temp,i+1);
        temp.pop_back();
        recursive(nums,ans,temp,i+1);
    }

};