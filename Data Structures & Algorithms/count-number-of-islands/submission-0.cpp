class Solution {
    private:
    int rc;
    int cc;
    int count;

    vector<pair<int, int>> deltas = {{-1, 0}, {1, 0}, {0, -1}, {0, 1} };
public:
    int numIslands(vector<vector<char>>& grid) {
        count = 0;
        rc = grid.size();
        cc = grid[0].size();
        if(rc == 0 || cc == 0) return count;
        for(int i = 0; i < rc; i++) {
            for(int j = 0; j < cc; j++) {
                if(grid[i][j] == '1') {
                    count++;
                    fillIsland(grid, i, j);
                }
            }
        }
        return count;
    }

    void fillIsland(vector<vector<char>>& grid, int i, int j) {
        if(i < 0 || i >= rc || j < 0 || j >= cc) return;
        if(grid[i][j] == '0') return;
        grid[i][j] = '0';
        for(auto &[dr, dc] : deltas) {
            int newX = i +dr;
            int newY = j + dc;
            fillIsland(grid, newX, newY);
        }
    }
};
