class Solution {
public:
    int maxArea=0;

    int dfs(int i,int j,vector<vector<int>>& grid){
        int up=0;
        int down=0;
        int left=0;
        int right=0;
        //up
        if(i>0&&grid[i-1][j]==1){
            grid[i-1][j]=0;
            up=dfs(i-1,j,grid);
        }
        //down
        if(i<grid.size()-1&&grid[i+1][j]==1){
            grid[i+1][j]=0;
            down=dfs(i+1,j,grid);
        }
        //left
        if(j>0&&grid[i][j-1]==1){
            grid[i][j-1]=0;
            left=dfs(i,j-1,grid);
        }
        //right
        if(j<grid[0].size()-1&&grid[i][j+1]==1){
            grid[i][j+1]=0;
            right=dfs(i,j+1,grid);
        }

        return (1+up+down+left+right);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    grid[i][j]=0;
                    maxArea=max(dfs(i,j,grid),maxArea);
                }
            }
        }

        return maxArea;
    }
};
