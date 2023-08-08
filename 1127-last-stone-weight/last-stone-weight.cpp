class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        //use a priority queue in rising order
        //top is greater one
        //less is next greatest one

        if (stones.size() == 1) {
            return stones[0];
        }

        priority_queue<int> p;

        for (int i = 0; i < stones.size(); i++) {
            p.push(stones[i]);
        }

        while (p.size() > 1) {
            int top = p.top();
            p.pop();
            int less = p.top();
            p.pop();

            //case if same
            if (top - less != 0) {
                int diff = top - less;
                p.push(diff);
            }

            //case not same do nothing
        }
        if (p.empty()) {
            return 0;
        }
        else {
            return p.top();
        }
    }
};