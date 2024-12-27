class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(),candidates.end());
    vector<vector<int>>ans;
    vector<int>temp;
    recursive(candidates,ans,temp,0,target); 
    return ans;   
    }

    void recursive(vector<int>& candidates,vector<vector<int>>& ans,vector<int>& temp,int i,int target)
    {
        if(target == 0)
        {
            ans.push_back(temp);
            return;
        }

        if(target < 0 || i == candidates.size())
        {
            return;
        }

        temp.push_back(candidates[i]);
        recursive(candidates,ans,temp,i+1,target - candidates[i]); //pick
        temp.pop_back();
        int nextIndex = i + 1;
        while (nextIndex < candidates.size() && candidates[nextIndex] == candidates[i]) {
            nextIndex++;
        }
        recursive(candidates,ans,temp,nextIndex,target); //Not pick
    }
};