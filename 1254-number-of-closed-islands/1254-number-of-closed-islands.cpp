class Solution {
public:
    int n, m;
    bool dfs(vector<vector<int>>& grid, int row, int col) {

        if (row >= n || row < 0 || col >= m || col < 0)
            return false; // out of bound
        if (grid[row][col] == 1)
            return true;
        grid[row][col] = 1;
        bool left_closed = dfs(grid, row, col - 1);
        bool right_closed = dfs(grid, row, col + 1);
        bool up_closed = dfs(grid, row - 1, col);
        bool down_closed = dfs(grid, row + 1, col);
        return left_closed && right_closed && up_closed && down_closed;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int count = 0;
        n = grid.size();
        m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    if (dfs(grid, i, j) == true)
                        count++;
                }
            }
        }
        return count;
    }
};