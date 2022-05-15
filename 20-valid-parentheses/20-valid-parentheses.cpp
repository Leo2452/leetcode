class Solution {
public:
    
    bool isOpen(char c) {
        return c == '(' || c == '[' || c == '{';
    }
    
    bool canClose(char c1, char c2) {
        return (c1 == '(' && c2 == ')') ||
               (c1 == '[' && c2 == ']') ||
               (c1 == '{' && c2 == '}');
    }
    
    bool isValid(string str) {
        stack<char> s;
        for (int i = 0; i < str.size(); i++) {
            if (isOpen(str.at(i))) {
                s.push(str.at(i));
            } else {
                if (s.empty() || !canClose(s.top(), str.at(i))) {
                    return false;
                }
                s.pop();
            }
        }
        return s.empty();
    }
};