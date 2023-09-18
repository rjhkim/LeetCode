class Solution {
public:
    template<typename K, typename V>
    std::pair<K,V> getMaximumValue(const std::map<K,V> &map) {
        return *std::max_element(map.begin(), map.end(), [](std::pair<K,V> const &x, std::pair<K,V> const &y) {
            return x.second < y.second;
        });
    }
    int characterReplacement(string s, int k) {
        int result = 0;
        //set result to length of window, slide it shift left pointer to right when the window breaks the constraint
        map<char, int> hash;

        int left = 0;
        for (int r = 0; r < s.size(); r++) {
            hash[s[r]]++;

            while (((r - left + 1) - getMaximumValue(hash).second) > k) {
                hash[s[left]]--;
                left += 1;
            }

            result = max(result, r - left + 1);
        }
        
        return result;
    }
};