class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        queue<pair<int,int>> q;
        int islands = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    pair<int,int> temp = {i, j};
                    q.push(temp);
                    grid[i][j] = '0';
                    islands++;
                    bfs(grid, q, islands);
                }
            }
        }
        return islands;
    }

    void bfs(vector<vector<char>>& grid, queue<pair<int,int>> q, int islands) {
        while (!q.empty()) {
            pair<int,int> f = q.front();
            q.pop();
            int i = f.first;
            int j = f.second;
            int top = i + 1;
            int right = j + 1;
            int left = j - 1;
            int bottom = i - 1;

            if (top < grid.size()) {
                if (grid[top][j] == '1') {
                    pair<int, int> temp = {top, j};
                    q.push(temp);
                    grid[top][j] = '0';
                }
            } 

            if (right < grid[0].size()) {
                if (grid[i][right] == '1') {
                    pair<int, int> temp = {i, right};
                    q.push(temp);
                    grid[i][right] = '0';
                }
            } 

            if (left >= 0) {
                if (grid[i][left] == '1') {
                    pair<int, int> temp = {i, left};
                    q.push(temp);
                    grid[i][left] = '0';
                }
            } 

            if (bottom >= 0) {
                if (grid[bottom][j] == '1') {
                    pair<int, int> temp = {bottom, j};
                    q.push(temp);
                    grid[bottom][j] = '0';
                }
            } 
        }//while
    }
};