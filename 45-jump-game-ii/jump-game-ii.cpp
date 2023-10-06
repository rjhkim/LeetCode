class Solution {
public:
    int jump(vector<int>& nums) {
        int result = 0;
        int left = 0;
        int right = 0;
        //left and right tell us our window, levels
        //each level is an increment
        //simplified BFS on one dimensional array, use left and right variables
        while (right < nums.size() - 1) {
            int furthest = 0;
            for (int i = left; i <= right; i++) {
                furthest = max(furthest, i + nums[i]);
            }
            left = right + 1;
            right = furthest;
            result++;
        }

        return result;

    }
};