class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int totalXor = 0;
        bool hasNonZero = false;

        for (int x : nums) {
            totalXor ^= x;
            if (x != 0) {
                hasNonZero = true;
            }
        }

        // If all elements are zero, no subsequence can have non-zero XOR
        if (!hasNonZero) {
            return 0;
        }

        // If total XOR is already non-zero, take the whole array
        if (totalXor != 0) {
            return nums.size();
        }

        // Otherwise, exclude any one non-zero element to get non-zero XOR
        return nums.size() - 1;
    }
};