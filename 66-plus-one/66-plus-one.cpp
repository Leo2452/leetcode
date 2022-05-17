class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool carry_over = true;
        for (auto rit = digits.rbegin(); rit != digits.rend(); rit++) {
            if (carry_over) {
                *rit += 1;
                carry_over = (*rit == 10);
                if (carry_over) {
                    *rit = 0;
                }
            } else {
                return digits;
            }
        }
        if (carry_over) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};