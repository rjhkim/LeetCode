class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int left = 0;
        int right = matrix[0].size() - 1; // col

        while (left < right) {
            //i is used to handle all swaps in a row, for example
            //row of 4, can't only swap the first element, need to go inside
            for (int i = 0; i < right - left; i++) {
                int top = left;
                int bottom = right;

                //save the top left value
                int top_left = matrix[top][left + i];

                //move bottom left to top left
                matrix[top][left + i] = matrix[bottom - i][left];

                //move bottom right into bottom left
                matrix[bottom - i][left] = matrix[bottom][right - i];

                //move top right into bottom right
                matrix[bottom][right - i] = matrix[top + i][right];

                //move top left into top right
                matrix[top + i][right] = top_left;
            }//for
            right--;
            left++;
        }
    }
};