class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rows, cols; // each row and col
        map<pair<int, int>, unordered_set<char>> squares; // the 3x3 box

        for(int r = 0; r < 9; ++r){
            for(int c = 0; c < 9; ++c){
                if(board[r][c] == '.') continue; // continue since no constraints

                pair<int, int> squareKey = {r / 3, c / 3}; //identifying the box
                
                //Before placing this digit, check whether it's already been 
                //seen in this row, this column, or this box. If any of those is true, you
                //have a duplicate   
                
                if(rows[r].count(board[r][c]) || cols[c].count(board[r][c]) || squares[squareKey].count(board[r][c])){
                    return false; // theres a duplicate
                }

                
                //if no duplicate was found, record this digit as 
                //'now seen' in its row, column, and box, then move on
                rows[r].insert(board[r][c]);
                cols[c].insert(board[r][c]);
                squares[squareKey].insert(board[r][c]);
            }
        }
        return true; // no duplicate
    }
};
