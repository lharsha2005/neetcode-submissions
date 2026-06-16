class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& grid,int dis){
        if(i < 0 || i >= grid.size() ||
            j < 0 || j >= grid[0].size() ||
            grid[i][j] == -1)
            return;

        if(dis > grid[i][j])
            return;

        grid[i][j] = dis;

        dfs(i+1,j,grid,dis+1);
        dfs(i-1,j,grid,dis+1);
        dfs(i,j+1,grid,dis+1);
        dfs(i,j-1,grid,dis+1);
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
