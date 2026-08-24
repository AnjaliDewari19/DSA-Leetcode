class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        std::vector<long long> prefix(n);
        prefix[0] = stones[0];
        for (int i = 1; i < n; ++i) {
            prefix[i] = prefix[i - 1] + stones[i];
        }

        // Start from the last prefix sum
        long long maxDiff = prefix[n - 1];

        // Work backward from n - 2 down to 1
        for (int i = n - 2; i >= 1; --i) {
            maxDiff = std::max(maxDiff, prefix[i] - maxDiff);
        }
        return maxDiff;
    }
};
