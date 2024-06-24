class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        //add all values of nums into priority queue in decrease order, a min priority queue
        //as you are adding, you delete / pop values if. itexceeds k
        //push/pop priority queue = log(n)
        //top access = O(1)
        k_values = k;
        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
            if (pq.size() > k) {
                pq.pop();
            }
        }
    }
    int add(int val) {
        pq.push(val);
        if (pq.size() > k_values) {
            pq.pop();
        }
        return pq.top();
    }
private:
    int k_values;
    priority_queue<int, vector<int>, greater<int>> pq;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */