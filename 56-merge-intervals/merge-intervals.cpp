class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
     sort(intervals.begin(), intervals.end());
    int st =0;
    for(int i=1;i<intervals.size();i++)
    {
        if(intervals[st][1] >= intervals[i][0])
        {
            intervals[st][1] = max(intervals[st][1],intervals[i][1]);
        }
        else{
            st++;
            intervals[st]= intervals[i];
        }
        
    }
            intervals.resize(st + 1); 
        return intervals;
    }
};