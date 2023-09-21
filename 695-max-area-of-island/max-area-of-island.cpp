class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        //use bfs and queue
        queue<pair<int,int>> q;
        int result = 0;
        //double nested for loop to identify island
        for (int i = 0; i < grid.size(); i++) { //row
            for (int j = 0; j < grid[i].size(); j++) { //column
                if (grid[i][j] == 1) {
                    int current = 1;
                    pair<int,int> temp = {i, j};
                    q.push(temp);
                    grid[i][j] = 0;
                    int curr = bfs(grid, result, q, current); //should be 1
                    if (curr >= result) {
                        result = curr;
                    }
                }
            }
        }
        return result;
    }

    int bfs(vector<vector<int>>& grid, int result, queue<pair<int,int>> q, int current) {
        while (!q.empty()) {
            pair<int,int> front = q.front();
            q.pop();
            int i = front.first;
            int j = front.second;
            int top = i + 1;
            int bottom = i - 1;
            int right = j + 1;
            int left = j - 1;
            if (top < grid.size()) {
                if (grid[top][j] == 1) {
                    grid[top][j] = 0;
                    pair<int,int> temp = {top, j};
                    q.push(temp);
                    current++;
                }
            }
            if (bottom >= 0) {
                if (grid[bottom][j] == 1) {
                    grid[bottom][j] = 0;
                    pair<int,int> temp = {bottom, j};
                    q.push(temp);
                    current++;
                }
            }
            if (right < grid[0].size()) {
                if (grid[i][right] == 1) {
                    grid[i][right] = 0;
                    pair<int,int> temp = {i, right};
                    q.push(temp);
                    current++;
                }
            }
            if (left >= 0) {
                if (grid[i][left] == 1) {
                    grid[i][left] = 0;
                    pair<int,int> temp = {i, left};
                    q.push(temp);
                    current++;
                }
            }
        }//while loop
        return current;
    }
};