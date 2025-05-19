// Question Link :- https://leetcode.com/problems/01-matrix/description/
// 01 Matrix


// T.C = O(n*m)
// S.C = O(n*m)
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int, int>> que;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    que.push({i, j});
                    visited[i][j] = true;
                }
            }
        }

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};

        while(!que.empty()) {
            int x = que.front().first;
            int y = que.front().second;
            que.pop();

            for(int i=0; i<4; i++) {
                int di = x + dx[i];
                int dj = y + dy[i];

                if(di >= 0 && di < n && dj >= 0 && dj < m && !visited[di][dj]) {
                    mat[di][dj] = mat[x][y] + 1;
                    que.push({di, dj});
                    visited[di][dj] = true;
                }
            }
        }
        return mat;
    }
};