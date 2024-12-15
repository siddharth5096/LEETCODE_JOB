class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int rs = matrix.size();
    int cs = matrix[0].size();
    int low = 0;
    int high = (rs * cs)-1; 
    while(low <= high)
    {
        int mid = (low+high)/2;
        int rInd = mid/cs;
        int cInd = mid%cs;
        if(matrix[rInd][cInd] == target)
        {
            return true;
        }
        else if(matrix[rInd][cInd] < target)
        {
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return false;  
    }
};