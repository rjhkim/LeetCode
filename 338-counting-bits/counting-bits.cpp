class Solution {
public:
    vector<int> countBits(int n) {
        //for loop
        vector<int> ans;
        ans.resize(n + 1, 0);
        int offset = 1;

        for (int i = 1; i < n + 1; i++) {
            if ((offset * 2) == i) {
                offset = i;
            }
            ans[i] = 1 + ans[i - offset];
        }

        return ans;
    }
};