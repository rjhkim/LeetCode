class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;

        //if see opening bracket, add it to the stack
        //for each closing bracket, check the top;/.
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stack.push(s[i]);
            }
            else {
                if (stack.empty()) {
                    stack.push(s[i]);
                }
                else if (!stack.empty() && stack.top() == '(') {
                    if (s[i] == ')') {
                        stack.pop();
                    }
                    else {
                        stack.push(s[i]);
                    }

                }
                else if (!stack.empty() && stack.top() == '{') {
                    if (s[i] == '}') {
                        stack.pop();
                    }
                    else {
                        stack.push(s[i]);
                    }
                }
                else if (!stack.empty() && stack.top() == '[') {
                   if (s[i] == ']') {
                        stack.pop();
                    }
                    else {
                        stack.push(s[i]);
                    }
                }
            }
        }
        if (stack.empty()) {
            return true;
        }
        else {
            return false;
        }
    }
};