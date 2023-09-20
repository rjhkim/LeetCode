class Solution {
public:
    int rob(vector<int>& nums) {
        int rob1 = 0;
        int rob2 = 0;
        /*
        1, 2, 3, 1
        i = 0
        temp = max (1 + 0, 0)
        temp = 1
        rob1 = 0
        rob2 = 1

        i = 1
        temp = max (2 + 0, 1)
        temp = 2
        rob1 = 1
        rob2 = 2

        i = 3
        temp = max (3 + 1, 2)
        temp = 4
        rob1 = 1
        rob2 = 2

        */
        for (int i = 0; i < nums.size(); i++) {
            int temp = max(nums[i] + rob1, rob2);
            rob1 = rob2;
            rob2 = temp;
        }
        return rob2;
    }
};