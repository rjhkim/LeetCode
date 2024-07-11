class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        //main idea, implement the tree algorithm
        //variables needed for dfs 1. res 2d vector, 2. cur vector, 3. nums 
        //4. index
        //base case when i = nums.size(), then push cur into res
        //call dfs with subarray cur with nums[i], pushed in and
        //call dfs with subarray cur without nums[i] (popped) and index++ until
        //nums[i] != original nums[i] (remove duplicates)
        int index = 0;
        vector<vector<int>> res;
        vector<int> cur;
        sort(nums.begin(), nums.end()); //need to sort
        dfs(cur, res, nums, index);

        return res; 
    }

    void dfs(vector<int>& cur, vector<vector<int>>& res, vector<int>& nums, int index) {
        if (index >= nums.size()) {
            res.push_back(cur);
            return;
        }

        //call dfs with subarray cur with nums pushed in
        cur.push_back(nums[index]);
        dfs(cur, res, nums, index + 1);

        //call dfs with subarray cur without nums
        cur.pop_back();
        int check = nums[index];
        while (index < nums.size() && nums[index] == check) {
            index++;
        } //end while this increments i until we see a new number
        dfs(cur, res, nums, index);
    }
};
