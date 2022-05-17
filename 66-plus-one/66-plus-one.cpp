class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (auto rit = digits.rbegin(); rit != digits.rend(); rit++) { 
            if (*rit != 9) {
                *rit += 1;
                return digits;
            }
            *rit = 0;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};