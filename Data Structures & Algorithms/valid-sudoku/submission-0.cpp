class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){

                if(board[i][j] == '.') continue;

                if(!checkrow(i,j,board) ||
                   !checkcolumn(i,j,board) ||
                   !checkbox(i,j,board))
                    return false;
            }
        }

        return true;
    }

    bool checkrow(int i,int j,vector<vector<char>>& board){
        for(int aj=0;aj<9;aj++){
            if(aj!=j && board[i][j]==board[i][aj])
                return false;
        }
        return true;
    }

    bool checkcolumn(int i,int j,vector<vector<char>>& board){
        for(int ai=0;ai<9;ai++){
            if(ai!=i && board[i][j]==board[ai][j])
                return false;
        }
        return true;
    }

    bool checkbox(int i,int j,vector<vector<char>>& board){

        int rowStart = (i/3)*3;
        int colStart = (j/3)*3;

        for(int ai=rowStart; ai<rowStart+3; ai++){
            for(int aj=colStart; aj<colStart+3; aj++){

                if((ai!=i || aj!=j) &&
                   board[i][j]==board[ai][aj])
                    return false;
            }
        }

        return true;
    }
};