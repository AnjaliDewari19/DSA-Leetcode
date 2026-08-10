class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        
        // suffix_sum[i] stores the sum of stones from index i to n-1
        vector<int> suffix_sum(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            suffix_sum[i] = suffix_sum[i + 1] + piles[i];
        }
        
        // dp[i][M] stores max stones the current player can get starting from index i with parameter M
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));
        
        // Helper lambda function for DFS with memoization
        auto solve = [&](auto& self, int i, int M) -> int {
            // Base case: if remaining piles are less than or equal to 2 * M,
            // player can take all remaining piles.
            if (i + 2 * M >= n) {
                return suffix_sum[i];
            }
            
            if (dp[i][M] != 0) {
                return dp[i][M];
            }
            
            int min_opponent_score = INT_MAX;
            for (int X = 1; X <= 2 * M; ++X) {
                int next_M = max(M, X);
                min_opponent_score = min(min_opponent_score, self(self, i + X, next_M));
            }
            
            // Current player gets total remaining stones minus the opponent's best outcome
            dp[i][M] = suffix_sum[i] - min_opponent_score;
            return dp[i][M];
        };
        return solve(solve, 0, 1);
    }
};
