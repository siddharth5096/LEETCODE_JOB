class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        vector<int> extraR(rows, 0); 
        vector<int> extraC(cols, 0); 

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (matrix[r][c] == 0) {
                    extraR[r] = 1;
                    extraC[c] = 1;
                }
            }
        }

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (extraR[r] == 1 || extraC[c] == 1) {
                    matrix[r][c] = 0;
                }
            }
        }
    }
};
