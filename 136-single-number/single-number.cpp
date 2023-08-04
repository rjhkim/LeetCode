class Solution {
public:
    int singleNumber(vector<int>& nums) {
       map<int,int> m;

       for (int i = 0; i < nums.size(); i++) {
           m[nums[i]]++;
       } 

       for (auto j : m) {
           if (j.second == 1) {
               return j.first;
           }
       }

       return 0;
    }
};