class Solution {
public:
    bool isHappy(int n) {
        //how do I know if it will loop endlessly
        unordered_set<int> s;

        while (s.find(n) == s.end()) {
            s.insert(n);
            n = new_num(n);

            if (n == 1) {
                return true;
            }
        }

        return false;
        
    }

    int new_num(int n) {
        int squared = 0;
        while (n != 0) {
            //get digits and divide
            int digit = n % 10;
            n = n / 10; //reduces one digit

            squared += (digit * digit);
        }
        return squared;
    }
};