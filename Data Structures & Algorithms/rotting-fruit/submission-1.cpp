class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> rotten;
        int fresh=0;
        int minutes = 0;

        vector<vector<int>> dir={
            {-1,0},
            {1,0},
            {0,-1},
            {0,1}
        };

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2)   rotten.push({i,j});
                else if(grid[i][j]==1)  fresh++;
            }
        }


        while(!rotten.empty() && fresh > 0){
            int sz = rotten.size();

            while(sz--){
                auto [r,c] = rotten.front();
                rotten.pop();

                for(auto &d : dir){
                    int row = r + d[0];
                    int col = c + d[1];

                    if(row < 0 || row >= grid.size() ||
                    col < 0 || col >= grid[0].size() ||
                    grid[row][col] != 1)
                        continue;

                    grid[row][col] = 2;
                    fresh--;
                    rotten.push({row,col});
                }
            }

            minutes++;
        }

        return fresh == 0 ? minutes : -1;;
    }
};
