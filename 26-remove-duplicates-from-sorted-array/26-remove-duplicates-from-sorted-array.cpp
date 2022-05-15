class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int dupes = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1]) {
                dupes++;
            } else {
                nums[i-dupes] = nums[i];
            }
        }
        return nums.size() - dupes;
    }
};