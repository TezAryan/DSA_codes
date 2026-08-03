class Solution {
        vector<int> dr = {0, 1, 0, -1};
        vector<int> dc = {-1, 0, 1, 0};
public:
    void dfs(int row, int col, vector<vector<char>>& board,
             vector<vector<int>>& vis) {
        int m = board.size();
        int n = board[0].size();

        vis[row][col] = 1; 

         for (int i = 0; i < 4; i++) {

            int nr = row + dr[i];
            int nc = col + dc[i];

            if (nr >= 0 && nr < m &&
                nc >= 0 && nc < n && !vis[nr][nc] && board[nr][nc] == 'O') {
                    dfs( nr , nc , board , vis);
                }
         }

    }
    void solve(vector<vector<char>>& board) {

        int m = board.size();
        int n = board[0].size();

        if (m == 0)
            return;
        vector<vector<int>> vis(m, vector<int>(n, 0));

        // Top row
for (int j = 0; j < n; j++)
{
    if (board[0][j] == 'O' && !vis[0][j])
        dfs(0, j, board, vis);
}

// Left column
for (int i = 0; i < m; i++)
{
    if (board[i][0] == 'O' && !vis[i][0])
        dfs(i, 0, board, vis);
}

// Bottom row
for (int j = 0; j < n; j++)
{
    if (board[m - 1][j] == 'O' && !vis[m - 1][j])
        dfs(m - 1, j, board, vis);
}

// Right column
for (int i = 0; i < m; i++)
{
    if (board[i][n - 1] == 'O' && !vis[i][n - 1])
        dfs(i, n - 1, board, vis);
}

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O' && !vis[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};