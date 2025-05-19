// Question Link :- https://leetcode.com/problems/number-of-enclaves/
// Number of Enclaves


// Approach - 1 (DFS)
// T.C = O(n*m)
// S.C = O(n*m)
class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited, int n, int m) {
        if (i < 0 || i >= n || j < 0 || j >= m || visited[i][j] || grid[i][j] == 0) {
            return;
        }
        visited[i][j] = true;

        dfs(i + 1, j, grid, visited, n, m);
        dfs(i - 1, j, grid, visited, n, m);
        dfs(i, j + 1, grid, visited, n, m);
        dfs(i, j - 1, grid, visited, n, m);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        long long count = 0;

        // Traverse the boundary columns
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1 && !visited[i][0]) {
                dfs(i, 0, grid, visited, n, m);
            }
            if (grid[i][m-1] == 1 && visited[i][m-1] == false) {
                dfs(i, m-1, grid, visited, n, m);
            }
        }

        // Traverse the boundary rows
        for (int i = 0; i < m; i++) {
            if (grid[0][i] == 1 && visited[0][i] == false) {
                dfs(0, i, grid, visited, n, m);
            }
            if (grid[n-1][i] == 1 && visited[n-1][i] == false) {
                dfs(n-1, i, grid, visited, n, m);
            }
        }

        // Count the number of enclaves (cells that are land and not visited)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && visited[i][j] == false) {
                    count++;
                }
            }
        }
        return count;
    }
};





// Approach - 2 (BFS)
// T.C = O(n*m)
// S.C = O(n*m)
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int,int>> que;

        // Check the first and last column
        for(int i=0; i<n; i++){
            if(grid[i][0] == 1) {
                que.push({i, 0});
                visited[i][0] = true;
            }
            if(grid[i][m-1] == 1) {
                que.push({i, m-1});
                visited[i][m-1] = true;
            }
        }
        // Check the first and last row
        for(int i=0; i<m; i++){
            if(grid[0][i] == 1) {
                que.push({0, i});
                visited[0][i] = true;
            }
            if(grid[n-1][i] == 1) {
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
                if(di>=0 && dj>=0 && di<n && dj<m && grid[di][dj] == 1 && !visited[di][dj]) {
                    que.push({di, dj});
                    visited[di][dj] = true;
                }
            }
        }

        // Count the number of enclaves (cells that are land and not visited)
        long long cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && !visited[i][j]) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};