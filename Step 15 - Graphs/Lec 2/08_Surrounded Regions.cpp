// Question Link :- https://leetcode.com/problems/surrounded-regions/
// Surrounded Regions

// Approach - 1 (DFS)
// T.C = O(n*m)
// S.C = O(n*m)
class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& board, vector<vector<bool>>& visited, int n, int m) {
        if (i < 0 || i >= n || j < 0 || j >= m || visited[i][j] || board[i][j] == 'X') {
            return;
        }
        visited[i][j] = true;

        dfs(i + 1, j, board, visited, n, m);
        dfs(i - 1, j, board, visited, n, m);
        dfs(i, j + 1, board, visited, n, m);
        dfs(i, j - 1, board, visited, n, m);
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        // Check the first and last column
        for(int i=0; i<n; i++) {
            if (board[i][0] == 'O' && !visited[i][0]) {
                dfs(i, 0, board, visited, n, m);
            }
            if (board[i][m - 1] == 'O' && !visited[i][m - 1]) {
                dfs(i, m - 1, board, visited, n, m);
            }
        }
        // Check the first and last row
        for (int i = 0; i < m; i++) {
            if (board[0][i] == 'O' && !visited[0][i]) {
                dfs(0, i, board, visited, n, m);
            }
            if (board[n - 1][i] == 'O' && !visited[n - 1][i]) {
                dfs(n - 1, i, board, visited, n, m);
            }
        }
        // Convert all unvisited 'O's to 'X'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && visited[i][j]==false) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};





// Approach - 2 (BFS)
// T.C = O(n*m)
// S.C = O(n*m)
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int,int>> que;

        // Check the first and last column
        for(int i=0; i<n; i++){
            if(board[i][0] == 'O') {
                que.push({i, 0});
                visited[i][0] = true;
            }
            if(board[i][m-1] == 'O') {
                que.push({i, m-1});
                visited[i][m-1] = true;
            }
        }
        // Check the first and last row
        for(int i=0; i<m; i++){
            if(board[0][i] == 'O') {
                que.push({0, i});
                visited[0][i] = true;
            }
            if(board[n-1][i] == 'O') {
                que.push({n-1, i});
                visited[n-1][i] = true;
            }
        }

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        while(!que.empty()){
            pair<int,int> p = que.front();
            int x = p.first;
            int y = p.second;
            que.pop();

            for(int i=0; i<4; i++) {
                int di = x + dx[i];
                int dj = y + dy[i];
                if(di>=0 && dj>=0 && di<n && dj<m && board[di][dj] == 'O' && !visited[di][dj]) {
                    que.push({di, dj});
                    visited[di][dj] = true;
                }
            }
        }

        // Convert all unvisited 'O's to 'X'
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]=='O' && !visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};