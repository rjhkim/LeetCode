class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        /*
        data structure: hash map -> quick and fast lookup O(1)
        hash map memory complexity - n, 

        algorithm: loop through nums
        for each nums insert into hash map
        loop through hash map if count is greater than 1, return false

        */
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }

        for (auto i : m) {
            if (i.second > 1) {
                return true;
            }
        }

        return false;
    }
};