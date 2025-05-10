class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
    long long sum1 =0,sum2=0,z1=0,z2=0;
    for(int i=0;i<nums1.size();i++)
    {
        sum1+=nums1[i];
        if(nums1[i]==0) 
        {
            z1++;
            sum1++;
        }
    
    }
    
    for(int i=0;i<nums2.size();i++)
    {
        sum2+=nums2[i];
        if(nums2[i]==0) 
        {
            z2++;
            sum2++;
        }
           
    }

    if(sum1 < sum2 && z1==0)
        return -1;
    else if(sum2 < sum1 && z2==0)
        return -1;
    else 
        return max(sum1,sum2);
    }
};