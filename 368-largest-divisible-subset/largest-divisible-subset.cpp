class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
    int n=nums.size();
    vector<int>dp(n,1);
    vector<int>sam(n,1);
    sort(nums.begin(),nums.end());
    for(int i=0;i<n;i++)
    {
        sam[i]=i;
        for(int prev=0;prev<i;prev++)
        {
            if(nums[i]%nums[prev]==0 && 1 + dp[prev] > dp[i])
            {
                dp[i] = 1 + dp[prev];
                sam[i] = prev;
            }
        }
    }
        
    int ans = -1;
    int lastIndex =-1;
    
    for(int i=0; i<=n-1; i++){
        if(dp[i]> ans){
            ans = dp[i];
            lastIndex = i;
        }
    }
        vector<int> temp;
    temp.push_back(nums[lastIndex]);
    
    while(sam[lastIndex] != lastIndex){ 
        
        lastIndex = sam[lastIndex];
        temp.push_back(nums[lastIndex]);    
    }
    
    reverse(temp.begin(),temp.end());
    return temp;
        
    }
};