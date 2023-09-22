class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (int i = 0; i < tokens.size(); i++) {
            string token = tokens[i];
            if (token.size() > 1 || isdigit(tokens[i][0])) {
                //token.size() > 1 makes sure + or - / * doesn't get stoied
                s.push(stoi(token));
                continue;
            }
            int second = s.top();
            s.pop();
            int first = s.top();
            s.pop();
            int result = 0;
            if (token == "+") {
                result = first + second;
            }
            if (token == "-") {
                result = first - second;
            }
            if (token == "*") {
                result = first * second;
            }
            if (token == "/") {
                result = first / second;
            }

            s.push(result);
        }//for
        return s.top();
    }
};