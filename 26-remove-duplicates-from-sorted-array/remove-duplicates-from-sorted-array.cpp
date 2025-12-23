class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j=0,ans=1,n=nums.size();
        if(n<2)
            return n;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]!=nums[j])
            {
                j++;
                nums[j]=nums[i];
                ans++;
            }
        }
        return ans;
    }
};