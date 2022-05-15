class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        while (i < nums.size()) {
            if (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
                // remove dup by shifting to the left
                nums.erase(nums.begin() + i);
            } else {
                i++;
            }
        }
        return nums.size();
    }
};