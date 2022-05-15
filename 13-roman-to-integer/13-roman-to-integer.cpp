class Solution {
public:
    std::map<char, int> romanValues_ = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
    
    bool isRomanShortcut(string s, int i) {
        s = string(1, s.at(i - 1)) + s.at(i);
        return s == "IV" || s == "IX" ||
               s == "XL" || s == "XC" ||
               s == "CD" || s == "CM";
    }
    
    int romanShortcutValue(string s, int i) {
        s = string(1, s.at(i - 1)) + s.at(i);
        if (s == "IV") {
            return 4;
        } else if (s == "IX") {
            return 9;
        } else if (s == "XL") {
            return 40;
        } else if (s == "XC") {
            return 90;
        } else if (s == "CD") {
            return 400;
        } else if (s == "CM") {
            return 900;
        }
        return -1; // not reachable
    }
        
    int romanToInt(string s) {
        int result = 0;
        int i = s.size() - 1;
        while (i >= 0) {
            if (i - 1 >= 0 && isRomanShortcut(s, i)) {
                result += romanShortcutValue(s, i);
                i--;
            } else {
                result += romanValues_[s.at(i)];
            }
            i--;
        }
        return result;        
    }
    
    
    
    
    
    
};