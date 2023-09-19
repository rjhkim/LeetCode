class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        int i = 0;
        int total = 0;
        dfs(candidates, target, result, i, current, total);
        return result;
    }

    void dfs(vector<int>& candidates, int target, vector<vector<int>> &result, int i,vector<int> &current, int total) {
        if (total == target) {
            vector<int> copy = current;
            result.push_back(copy);
            return;
        }
        if (i >= candidates.size() || total > target) {
            return;
        }
        current.push_back(candidates[i]);
        dfs(candidates, target, result, i, current, total + candidates[i]);
        current.pop_back();
        dfs(candidates, target, result, i + 1, current, total);
    }
};