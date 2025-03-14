class Solution {
public:
    bool isPos(long long &mid,vector<int>& candies, long long k)
    {
        long long cnt = 0;
        for(int i=0;i<candies.size();i++)
        {
            if(candies[i]>=mid)
            {
                cnt+=candies[i]/mid;
            }
        }
        return cnt>=k;
    }

    int maximumCandies(vector<int>& candies, long long k) {
    long long low = 1;
    long long high = *max_element(candies.begin(),candies.end());
    long long mid ;
    long long ans = 0;
    while(low<=high)
    {
        mid= (low+high)/2;
        if(isPos(mid,candies,k))
        {
            ans = mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }   
    return ans;
    }
};