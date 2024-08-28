class Solution {
public:
    int m,n;
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m = grid1.size();
        n = grid1[0].size();
        int count = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid2[i][j] && grid1[i][j]){
                    bool flag = true;
                    dfs(grid1,grid2,flag,i,j);
                    if(flag)
                        count++;      
                }
            }
        }
        return count;
    }
    
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2,bool &flag,int row,int col){
        if(row>=0 && row<m && col>=0 && col<n && grid2[row][col]){
            if(!grid1[row][col])
                flag = false;
            grid2[row][col] = 0;
            dfs(grid1,grid2,flag,row+1,col);
            dfs(grid1,grid2,flag,row-1,col);
            dfs(grid1,grid2,flag,row,col+1);
            dfs(grid1,grid2,flag,row,col-1);
        }
    }
};