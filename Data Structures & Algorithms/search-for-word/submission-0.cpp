class Solution {
public:
    bool rec(vector<vector<char>>& board, 
            string& word, 
            vector<vector<bool>>& visited,
            int i, 
            int x, 
            int y) {
        if (x<0 || x>=board.size() || y<0 || y>=board[0].size()) {
            return false;
        }

        if (visited[x][y] || word[i] != board[x][y]) {
            return false;
        }

        if (i == word.size()-1) {
            return true;
        } else {
            visited[x][y] = true;
            bool result = rec(board, word, visited, i+1, x+1, y)
                || rec(board, word, visited, i+1, x, y+1)
                || rec(board, word, visited, i+1, x-1, y)
                || rec(board, word, visited, i+1, x, y-1);
            visited[x][y] = false;
            return result;
        }

    }

    bool exist(vector<vector<char>>& board, string word) {
        const int X = board.size();
        const int Y = board[0].size();

        vector<vector<bool>> visited(X, vector<bool>(Y, false));

        for (int i=0 ; i<X ; ++i) {
            for (int j=0 ; j<Y ; ++j) {
                bool result = rec(board, word, visited, 0, i, j);
                if (result)
                    return true;
            }
        }

        return false;
    }
};
