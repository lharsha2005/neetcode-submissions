class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& grid){
        //up
        if(i>0 && grid[i-1][j]=='1'){
            grid[i-1][j]='*';
            dfs(i-1,j,grid);
        }
        //down
        if(i<grid.size()-1 && grid[i+1][j]=='1'){
            grid[i+1][j]='*';
            dfs(i+1,j,grid);
        }
        //left
        if(j>0 && grid[i][j-1]=='1'){
            grid[i][j-1]='*';
            dfs(i,j-1,grid);
        }
        //right
        if(j<grid[0].size()-1 && grid[i][j+1]=='1'){
            grid[i][j+1]='*';
            dfs(i,j+1,grid);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int count=0;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    grid[i][j]='*';
                    count++;
                    dfs(i,j,grid);
                }
            }
        }

        return count;
    }
};
