class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        vector<vector<int>> ans;
        for (int i = 0; i < points.size(); i++) {
            vector<int> curr;
            int xi = points[i][0];
            int yi = points[i][1];
            int calculation = (xi * xi) + (yi * yi);
            curr.push_back(calculation);
            curr.push_back(points[i][0]);
            curr.push_back(points[i][1]);
            q.push(curr);
        }//add the euclidean distance into priority queue

        //for loop for k closest (k smallest)
        for (int j = 0; j < k; j++) {
            ans.push_back({q.top()[1], q.top()[2]});
            q.pop();
        }

        return ans;
    }
};