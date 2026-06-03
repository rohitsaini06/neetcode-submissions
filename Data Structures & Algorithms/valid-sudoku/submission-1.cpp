class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows (9);
        vector<unordered_set<char>> cols (9);
        vector<unordered_set<char>> sqrs (9);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                auto res1 = rows[i].insert(board[i][j]);
                if (!res1.second) return false;
                auto res2 = cols[j].insert(board[i][j]);
                if (!res2.second) return false;
                auto res3 = sqrs[(i/3)*3 + (j/3)].insert(board[i][j]);
                if (!res3.second) return false;
            }
        }
        return true;

    }
};
