class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int newstart = newInterval[0];
        int newend = newInterval[1];
        int n = intervals.size();
        for (int i = 0; i < n; i++) {
            //case 1 if new interval is before current interval
            if (intervals[i][0] > newend) {
                ans.push_back(newInterval);
                copy(intervals.begin() + i, intervals.end(), back_inserter(ans));
                return ans;
            }
            //case 2 if new interval is after current interval
            else if (intervals[i][1] < newstart) {
                ans.push_back(intervals[i]);
            }

            //case 3 overlapping
            else {
                newInterval[0] = min(intervals[i][0], newInterval[0]);
                newInterval[1] = max(intervals[i][1], newInterval[1]);
               }  
        }
        ans.push_back(newInterval);
        return ans;
    }
};