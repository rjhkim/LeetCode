class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;

        if (nums.size() == 1) {
            vector<int> copy = nums;
            vector<vector<int>> temp = {copy};
            return temp;
        }

        for (int i = 0; i < nums.size(); i++) {
            int temp = nums[0];
            nums.erase(nums.begin());
            vector<vector<int>> p = permute(nums);

            for (int i = 0; i < p.size(); i++) {
                p[i].push_back(temp);
            }
            for (int i = 0; i < p.size(); i++) {
                ans.push_back(p[i]);
            }
            nums.push_back(temp);
        }

        return ans;

            
        }
};