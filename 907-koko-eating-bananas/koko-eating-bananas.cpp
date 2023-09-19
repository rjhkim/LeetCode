class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //initialize vector from 1 - greatest pile size
        int left = 1;
        int right = 0;
        for (int i = 0; i < piles.size(); i++) {
            right = max(right, piles[i]);
        }
        int result = right;

        while (left <= right) {
            int k = (left + right) / 2;
            long int hours = 0;
            for (int i = 0; i < piles.size(); i++) {
                hours += ceil((double) piles[i] / k);
            }
            if (hours <= h) {
                result = min(result, k);
                right = k - 1;
            }
            else {
                left = k + 1;
            }
        }

        return result;
    }
};