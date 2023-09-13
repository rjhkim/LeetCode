class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /*
            two while loops: first to find the row that the num is in
            second one to actually find number in that found row
        */
        int lowrow = 0;
        int highrow = matrix.size() - 1;

        while (lowrow < highrow) {
            int mid = lowrow + (highrow - lowrow) / 2;
            if (matrix[mid][0] == target) {
                return true;
            }
            if (matrix[mid][0] < target && target < matrix[mid + 1][0]) {
                lowrow = mid;
                break;
            }
            else if (matrix[mid][0] < target) {
                lowrow = mid + 1;
            }
            else {
                highrow = mid - 1;

            }
        }

        int lowCol = 0;
        int highCol = matrix[0].size() - 1;
        //use lowrow
        while (lowCol <= highCol) {
            int mid = lowCol + (highCol - lowCol) / 2;
            if (matrix[lowrow][mid] == target) {
                return true;
            }
            else if (matrix[lowrow][mid] < target) {
                lowCol = mid + 1;
            }
            else {
                highCol = mid - 1;
            }
        }

        return false;
        
    }
};