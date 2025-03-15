class Solution {
public:
    bool canAssign(int &max_assign,vector<int>& nums, int k)
    {
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<=max_assign)
            {
                cnt++;
                i++;
            }
        }
        return cnt>=k;
    }

    int minCapability(vector<int>& nums, int k) {
    int low = *min_element(nums.begin(),nums.end());
    int high = *max_element(nums.begin(),nums.end());
    int mid ;
    int ans =0;
    while(low<=high)
    {
        mid = (low+high)/2;
        if(canAssign(mid,nums,k))
        {
            ans=mid;
            high = mid -1;
        }
        else
        {
            low = mid+1;
        }
    }
    return ans;    
    }
};