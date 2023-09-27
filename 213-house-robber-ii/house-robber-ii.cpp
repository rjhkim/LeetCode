class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        //partition the array and do the house robber 1 algorithms on both arrays
        vector<int> skip_one;
        for (int i = 1; i < nums.size(); i++) {
            skip_one.push_back(nums[i]);
        }
        vector<int> skip_last = nums;
        skip_last.pop_back();
        return max(helper(skip_one), helper(skip_last));

    }

    int helper(vector<int>& nums) {
        int rob1 = 0;
        int rob2 = 0;

        for (int i = 0; i < nums.size(); i++) {
            int newRob = max(nums[i] + rob1, rob2);
            rob1 = rob2;
            rob2 = newRob;
        }

        return rob2;
    }
};