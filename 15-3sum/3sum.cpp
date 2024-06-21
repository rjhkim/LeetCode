class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());
        // Start the outer loop that will establish the goal
        int size = nums.size();

        if (size < 3) {
            return ans;
        }

        int i = 0;

        while (i < size - 2) {
            // Skip duplicate elements
            if (i > 0 && nums[i] == nums[i - 1]) {
                i++;
                continue;
            }

            int target = 0 - nums[i];
            int left = i + 1;
            int right = size - 1;

            while (left < right) {
                // If left and right pointers added equals target
                if (nums[left] + nums[right] == target) {
                    vector<int> temp = {nums[i], nums[left], nums[right]};
                    ans.push_back(temp);

                    // Skip duplicates for left and right pointers
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;     
                    }
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    left++;
                    right--;
                }
                // Less than target
                else if ((nums[left] + nums[right]) < target) {
                    left++;
                }
                // Greater than target
                else {
                    right--;
                }
            }
            i++;
        }
        return ans;
    }

    /*
    Time Complexity:
    1. Sorting: O(n log n)
    2. Outer loop: O(n)
    3. Inner loop: O(n) in the worst case

    Therefore, the overall time complexity is O(n^2).

    Space Complexity: O(1) (excludin

*/
};