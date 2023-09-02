class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //sliding window requires left and right pointer
        set<char> set;
        int left = 0;
        int result = 0;
        for (int r = 0; r < s.size(); r++) {
            while (set.find(s[r]) != set.end()) { //already exists
                set.erase(s[left]);
                left += 1;
            }
            set.insert(s[r]);
            result = max(result, (r-left) + 1);
        }
        return result;
    }
};