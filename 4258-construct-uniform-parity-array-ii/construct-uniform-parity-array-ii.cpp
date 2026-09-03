class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int min_val = nums1[0];
        bool has_even = false, has_odd = false;

        for (int x : nums1) {
            min_val = min(min_val, x);
            if (x % 2 == 0) has_even = true;
            else has_odd = true;
        }

        if (!has_even || !has_odd) return true;
        return min_val % 2 != 0;
    }
};