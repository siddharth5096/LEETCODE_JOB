class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
    int n = amount.size();
    vector<vector<int>>adj(n);
    for (auto it : edges)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    vector<int>curr_path,bob_path;
    findBobPath(adj,bob,-1,curr_path,bob_path);
    int size = bob_path.size();
    int i;
    for(i=0;i<size/2;++i)
    {
        amount[bob_path[i]] = 0;
    }

    if (size % 2 == 1) amount[bob_path[i]] = 0;
    else amount[bob_path[i]] /= 2;

    return findMaxAliceIncome(adj,0,-1,amount);
    }

    bool findBobPath(vector<vector<int>>&adj,int bob,int parent,vector<int>&curr_path,vector<int>&bob_path)
    {
        if(bob == 0)
        {
            bob_path = curr_path;
            return true;
        }
        curr_path.push_back(bob);
        for(int nbr : adj[bob])
        {
            if(nbr!=parent && findBobPath(adj,nbr,bob,curr_path,bob_path))
                return true;            
        }
        curr_path.pop_back();
        return false;
    }
    
    int findMaxAliceIncome(vector<vector<int>>&adj,int alice,int parent,vector<int>&amount)
    {
        int max_income = INT_MIN;
        for(int nbr:adj[alice])
        {
            if(nbr!=parent)
            {
                int inc = findMaxAliceIncome(adj,nbr,alice,amount);
                if(inc + amount[alice] > max_income)
                    max_income = inc + amount[alice];
            }
        }
        return max_income == INT_MIN?amount[alice]:max_income;
    }
};