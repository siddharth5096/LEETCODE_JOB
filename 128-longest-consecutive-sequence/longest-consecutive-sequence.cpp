class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    int ans = 0;
    unordered_set<int>set;
    for(int i=0;i<nums.size();i++)
    {
        set.insert(nums[i]);
    }   

    for(auto it:set)
    {       
        if(set.find(it-1) == set.end())
        {
            int cnt = 1;
            int val = it;
            while(set.find(val+1) != set.end())
            {
                cnt++;
                val++;
            }
            ans = max(ans,cnt);
        }
    }
    return ans; 
    }
};