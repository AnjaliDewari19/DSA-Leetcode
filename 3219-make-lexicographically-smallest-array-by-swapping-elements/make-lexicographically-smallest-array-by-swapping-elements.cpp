class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> paired(n);
        for (int i = 0; i < n; ++i) {
            paired[i] = {nums[i], i};
        }

        // Sort pairs by value
        sort(paired.begin(), paired.end());

        vector<int> ans(n);
        int i = 0;

        while (i < n) {
            int j = i;
            while (j + 1 < n && paired[j + 1].first - paired[j].first <= limit) {
                j++;
            }

            vector<int> indices;
            for (int k = i; k <= j; ++k) {
                indices.push_back(paired[k].second);
            }

            sort(indices.begin(), indices.end());

            for (int k = i; k <= j; ++k) {
                ans[indices[k - i]] = paired[k].first;
            }

            i = j + 1;
        }
        return ans;
    }
};
