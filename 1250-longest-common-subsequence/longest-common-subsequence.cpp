class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
         int m = text1.size();
         int n = text2.size();

         vector<vector<int>> dp (m + 1, vector<int>(n + 1));
        /*
        We create a 2D vector containing "m + 1"
        elements each having the value "vector<int> (n + 1)".
        "vector<int> (n + 1)" means a vector having "n + 1"
        elements
        Here these elements are vectors.
        */

         for (int i = m - 1; i >= 0; i--) {
             for (int j = n - 1; j >= 0; j--) {
                 if (text1[i] == text2[j]) {
                     dp[i][j] = 1 + dp[i + 1][j + 1];
                 }
                 else {
                     dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                 }
             }//for row
         }//for column

         return dp[0][0];
    }
};