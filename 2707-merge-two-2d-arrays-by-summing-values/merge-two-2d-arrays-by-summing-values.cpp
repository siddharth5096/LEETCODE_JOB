class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
    map<int, int> mp;
    for(int i=0;i<nums1.size();i++)
    {
        mp[nums1[i][0]] = nums1[i][1];
    }
    for(int i=0;i<nums2.size();i++)
    {
        if(mp.find(nums2[i][0]) != mp.end())
        {
            mp[nums2[i][0]] += nums2[i][1];
        }
        else {
            mp[nums2[i][0]] = nums2[i][1];  
        }
    }

    vector<vector<int>>res;
    for(auto it:mp)
    {
        res.push_back({it.first,it.second});
    }
    return res;
    }
};