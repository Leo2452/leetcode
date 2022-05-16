class Solution {
public:
    int lengthOfLastWord(string s) {
        int size = 0;
        for (auto rit = s.rbegin(); rit != s.rend(); rit++) { // reverse iteration
            if (*rit == ' ' && size > 0) {
                break;
            }
            if (*rit != ' ') {
                size++;
            }
        }
        return size;
    }
};