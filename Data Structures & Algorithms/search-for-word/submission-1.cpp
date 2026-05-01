class Solution {
    private:
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int rc, cc;
    vector<vector<int>> visited;
    bool isExist(vector<vector<char>>& board, string &word, int i, int j, int idx) {
        if(idx == word.size()) return true;
        if(i < 0 || i >= rc || j < 0 || j >= cc) return false;
        if(visited[i][j] == 1) return false;
        if(board[i][j] != word[idx]) return false;
        visited[i][j] =1;
        for(auto &[dr, dc] : dir) {
            int newR = i +dr;
            int newC = j +dc;
            if(isExist(board, word, newR, newC, idx+1)) return true;
        }
        visited[i][j] = 0;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        rc = board.size();
        cc = board[0].size();
        visited = vector<vector<int>>(rc, vector<int>(cc, 0));
        for(int i = 0; i < rc; i++) {
            for(int j = 0; j < cc; j++) {
                if(board[i][j] == word[0]) {
                    if(isExist(board, word, i, j, 0)) return true;
                }
            }
        }
        return false;
    }
};
