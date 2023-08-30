class Solution {
public:
    vector<int> countBits(int n) {
        //for loop
        vector<int> ans;

        for (int i = 0; i < n + 1; i++) {
            int temp = i;
            int count = 0;
            while (temp != 0) {
                if (temp & 1 == 1) {
                    count++;
                }
                temp = temp >> 1;
            }
            ans.push_back(count);
        }

        return ans;
    }
};