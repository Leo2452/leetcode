class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle == "" || haystack == needle) { return 0; }
        if (haystack.size() < needle.size()) { return -1; }

        for (int i = 0; i <= haystack.size() - needle.size(); i++) {
            bool needleFound = (haystack.substr(i, needle.size()) == needle);
            if (needleFound) {
                return i;
            }
        }
        return -1;
    }
};