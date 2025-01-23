class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int servers = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<int> rowCount(rows, 0), colCount(cols, 0);
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1 && (rowCount[i] > 1 || colCount[j] > 1)) {
                    servers++;
                }
            }
        }
        
        return servers;
    }
};
