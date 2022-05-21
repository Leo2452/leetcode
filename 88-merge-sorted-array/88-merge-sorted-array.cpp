class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // reverse merging trick
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1; // end of merged vec
        
        while (i >= 0 && j >= 0) {
            // add largest element to position k (the end)
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
        
        // finish for nums2
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};