class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& grid,int dis){
        if(grid[i][j] == -1 || dis > grid[i][j]){
            return;
        }

        grid[i][j] = dis;

        // up
        if(i > 0){
            dfs(i-1,j,grid,dis+1);
        }

        // down
        if(i < grid.size()-1){
            dfs(i+1,j,grid,dis+1);
        }

        // left
        if(j > 0){
            dfs(i,j-1,grid,dis+1);
        }

        // right
        if(j < grid[0].size()-1){
            dfs(i,j+1,grid,dis+1);
        }
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0){
                    dfs(i,j,grid,0);
                }
            }
        }
    }
};
