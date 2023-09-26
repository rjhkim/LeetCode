class Solution {
public:
    int findMin(vector<int>& nums) {
        //left middle and right pointer, find the pivot
        int result = nums[0];

        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            if (nums[left] < nums[right]) {
                result = min(result, nums[left]);
                break;
            }

            //if portion is not sorted, binary search
            int mid = (left + right) / 2;
            result = min(result, nums[mid]);
            if (nums[mid] >= nums[left]) {
                //part of left portion, search right
                left = mid + 1;
            }
            else {
                //in right sorted portion, search left
                right = mid - 1;
            }
        }//while

        return result;
    }
};