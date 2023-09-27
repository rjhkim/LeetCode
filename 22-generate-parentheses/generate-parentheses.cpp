class Solution {
public:
    vector<string> generateParenthesis(int n) {
        //back tracking
        //num of clsoe < num of open
        vector<string> res;
        string s = "";
        backtrack(s, n, res, 0, 0);
        return res;
    }

    void backtrack(string s, int n, vector<string> &res, int openN, int closedN) {
        if (openN == closedN && closedN == n) {
            res.push_back(s);
            return;
        }

        if (openN < n) {
            backtrack(s + "(", n, res, openN + 1, closedN);
        }

        if (closedN < openN) {
            backtrack(s + ")", n, res, openN, closedN + 1);
        }
    }
};