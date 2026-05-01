class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int cnt =0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(grid[i][j]=='1')
            {
                dfs(grid,i,j,m,n);
                cnt++;
            }
        }
    }    
        return cnt;
    }

    void dfs(vector<vector<char>>& grid,int i,int j,int row,int column)
    {
        if(i<0 || j<0 || i>row-1 || j>column-1 || grid[i][j]!= '1')
        {
            return;
        }

        grid[i][j] = '2';

        dfs(grid,i-1,j,row,column);
        dfs(grid,i+1,j,row,column);
        dfs(grid,i,j-1,row,column);
        dfs(grid,i,j+1,row,column);
    }
};