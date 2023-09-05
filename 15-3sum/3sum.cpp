class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0) {
                if (nums[i - 1] == nums[i]) {
                    continue;
                }
            }
            int first = nums[i];
            int second = i + 1;
            int third = nums.size() - 1;
            int target = 0;
            while (second < third) {
                int sum = first + nums[second] + nums[third];
                if (sum == target) {
                    vector<int> temp;
                    temp.push_back(first);
                    temp.push_back(nums[second]);
                    temp.push_back(nums[third]);
                    ans.push_back(temp);

                    while (second < third && nums[second] == nums[second + 1]) {
                        second++;
                    }
                    second++;

                    while (second < third && nums[third - 1] == nums[third]) {
                        third--;
                    }
                    third--;
                }
                else if (sum < target) {
                    second++;
                }
                else {
                    third--;
                }

            }
        }
        

        return ans;

    }
};