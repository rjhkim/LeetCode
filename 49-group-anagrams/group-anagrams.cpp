/*
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<map<char, int>> org;
        vector<vector<string>> ans;

        for (int i = 0; i < strs.size(); i++) {
            map<char, int> m;
            for (int j = 0; j < strs[i].size(); j++) {
                char word = strs[i][j];
                m[word]++;
            }
            org.push_back(m);
        }

        //loops through all words and makes a hash map
        bool last = false;

        for (int i = 0; i < org.size() - 1; i++) {
            if (strs[i] == "skip") {
                continue;
            }
            vector<string> current;
            current.push_back(strs[i]);
            for (int j = i + 1; j < org.size(); j++) {
                map<char, int> compare = org[i];

                if (compare == org[j]) {
                    if (j == org.size() - 1) {
                        last = true;
                    }
                    current.push_back(strs[j]);
                    strs[j] = "skip";
                    //adding it to the array
                }
            }
            ans.push_back(current);
        }

        if (last == false) {
            vector<string> l;
            l.push_back(strs[strs.size() - 1]);
            ans.push_back(l);
        }

        return ans;
    }
};
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m;
        vector<vector<string>> ans;

        for (int i = 0; i < strs.size(); i++) {
            string k = getKey(strs[i]);

            m[k].push_back(strs[i]);
        }

        for (auto i : m) {
            ans.push_back(i.second);
        }

        return ans;
    }

private:
    string getKey(string strs) {
        vector<int> count(26);
        for (int i = 0; i < strs.size(); i++) {
            count[strs[i] - 'a']++;
        }

        string key = "";

        for (int i = 0; i < count.size(); i++) {
            key.append(to_string(count[i]) + '9');
        }

        return key;
    }
};