class Solution {
public:
    int  merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        for (auto interval : intervals) {
            if (merged.empty() || merged.back()[1] <= interval[0]) {
                merged.push_back(interval);
            }
            else {
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }
        return merged.size();
    }
    bool checkValidCuts(int n, vector<vector<int>>& rect) {
      vector<vector<int>>ds1,ds2;
      for(auto s:rect){
          ds1.push_back({s[0],s[2]});
          ds2.push_back({s[1],s[3]});
      }
        
      auto ans1=merge(ds1);
      auto ans2=merge(ds2);
        
     return max(ans1,ans2)>2?1:0;
      
    }
};