class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> memo;

        memo.resize(cost.size());
        memo[cost.size() - 1] = cost[cost.size() - 1];
        memo[cost.size() - 2] = min(cost[cost.size() - 2], 
        cost[cost.size()-2] + memo[cost.size() - 1]);

        for (int i = memo.size() - 3; i >= 0; i--) {
            memo[i] = min(cost[i] + memo[i + 1], cost[i] + memo[i + 2]);
        }

        return min (memo[0], memo[1]);
    }
};