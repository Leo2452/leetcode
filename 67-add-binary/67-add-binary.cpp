class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int a_right = a.size() - 1;
        int b_right = b.size() - 1;
        bool carry_over = false;
        
        while (a_right >= 0 || b_right >= 0) {
            int sum = carry_over;
            if(a_right >= 0) sum += a[a_right--] - '0';
            if(b_right >= 0) sum += b[b_right--] - '0';
            carry_over = (sum > 1);
            result = to_string(sum % 2) + result;
        }
        if (carry_over) result = to_string(1) + result;
        return result;
    }
};