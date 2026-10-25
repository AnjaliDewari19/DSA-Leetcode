class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& grid){
        int row = grid.size() , cols = grid[0].size();

        if(r<0 || r>=row || c<0 || c>=cols || grid[r][c] == 1){
            return;
        }

        grid[r][c] = 1;

        dfs(r+1 , c , grid);
        dfs(r-1 , c , grid);
        dfs(r , c+1 , grid);
        dfs(r , c-1 , grid);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int row = grid.size(), cols = grid[0].size();

        for(int i=0; i<row ; ++i){
            for(int j=0 ; j<cols ; ++j){
                if((i==0 || i == row-1 || j==0 || j == cols-1) && grid[i][j] == 0){
                    dfs(i,j,grid);
                }
            }
        }

        int i_count = 0;
        for (int i=1 ; i<row-1 ; ++i){
            for(int j=1 ; j<cols-1 ; ++j){
                if(grid[i][j] == 0){
                    i_count++;
                    dfs(i,j,grid);
                }
            }
        }

        return i_count;
    }
};