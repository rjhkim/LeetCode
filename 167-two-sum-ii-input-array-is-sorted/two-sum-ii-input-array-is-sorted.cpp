class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        if (numbers.size() == 2) {
           vector<int> ans{1, 2};
           return ans;
        }

        vector<int> ans;

        int left = 0;
        int right = numbers.size() - 1;

        while (left < right) {
            int temp = numbers[left] + numbers[right];
            if (temp == target) {
                ans.push_back(left + 1); //added by one
                ans.push_back(right + 1);
                return ans;
            }
            else if (temp < target) {
                left++;
            }
            else {
                right--;
            }
        }

        return ans;
    }
};