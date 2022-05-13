class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {        
        map<int, int> numToIndex;
        for(int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            auto it = numToIndex.find(complement);
            if (it != numToIndex.end()) {
                return {it->second, i};
            }
            numToIndex.insert({nums[i], i});
        }
        return {};
    }   
};