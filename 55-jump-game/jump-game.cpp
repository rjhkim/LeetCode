class Solution {
public:
    bool canJump(vector<int>& nums) {
        //gready solution, start at end position see if pos before can reach it, slowly go back, shift goal O(n) time
        int goal = nums.size() - 1;

        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] + i >= goal) {
                goal = i;
            }
        }

        if (goal == 0) {
            return true;
        }

        else {
            return false;
        }
    }
};