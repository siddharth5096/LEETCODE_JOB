class Solution {
public:
    int n;
    char safe[10000];
    
    bool dfs(int i, vector<vector<int>>& graph) {
        if (safe[i] != -1) return safe[i]; // avoid of recomputing
        safe[i]=0; // Mark unsafe 
        for (int j : graph[i]) {
            if (!dfs(j, graph)) 
                return safe[i]=0; // any adj cell unsafe, i is unsafe
        }
        return safe[i]=1; // All adj cell are safe
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        n = graph.size();
        memset(safe, -1, n); // Initialize safe array to -1 
        vector<int> ans;
        
        for (int i = 0; i < n; i++) {
            if (dfs(i, graph)) 
                ans.push_back(i); //if node is safe
        }
        return ans;
    }
};