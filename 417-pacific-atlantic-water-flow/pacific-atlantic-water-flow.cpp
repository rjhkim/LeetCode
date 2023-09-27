class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        set<pair<int,int>> pac;
        set<pair<int,int>> atl;
        vector<vector<int>> res;

        for (int i = 0; i < cols; i++) {
            dfs(0, i, pac, heights[0][i], heights);
            dfs(rows - 1, i, atl, heights[rows - 1][i], heights);
        }

        for (int j = 0; j < rows; j++) {
            dfs(j, 0, pac, heights[j][0], heights) ;
            dfs(j, cols - 1, atl, heights[j][cols - 1], heights);
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                pair<int,int> temp = { i, j };
                if (pac.find(temp) != pac.end() && atl.find(temp) != atl.end()) {
                    //in both sets, means that the coordinates reach both pacific and atlantic ocean
                    vector<int> t = { i, j };
                    res.push_back(t);
                }
            }
        }

        return res;
    }


    void dfs(int row, int col, set<pair<int,int>> &visit, int prevHeight, vector<vector<int>>& heights) {
        pair<int,int> temp = { row, col };
        if (visit.find(temp) != visit.end() || row < 0 || col < 0 || row >= heights.size() || col >= heights[0].size() || heights[row][col] < prevHeight) {
            //exists, out of bounds if heights is less than prev height
            return;
        }
        visit.insert(temp);
        dfs(row + 1, col, visit, heights[row][col], heights);
        dfs(row - 1, col, visit, heights[row][col], heights);
        dfs(row, col + 1, visit, heights[row][col], heights);
        dfs(row, col - 1, visit, heights[row][col], heights);
    }
};