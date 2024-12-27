class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
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
        recursive(candidates,ans,temp,i,target - candidates[i]); //pick
        temp.pop_back();
        recursive(candidates,ans,temp,i+1,target); //Not pick
    }
};