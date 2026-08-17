class Solution {
    int memo[501][501];
    
    int solve(int i, int j, const vector<int>& pref) {
        if (i == j) return 0;
        if (memo[i][j] != -1) return memo[i][j];
        
        int maxScore = 0;
        int totalSum = pref[j + 1] - pref[i];
        
        for (int k = i; k < j; ++k) {
            int leftSum = pref[k + 1] - pref[i];
            int rightSum = totalSum - leftSum;
            
            if (leftSum < rightSum) {
                maxScore = max(maxScore, leftSum + solve(i, k, pref));
            } else if (rightSum < leftSum) {
                maxScore = max(maxScore, rightSum + solve(k + 1, j, pref));
            } else { // leftSum == rightSum
                maxScore = max(maxScore, leftSum + max(solve(i, k, pref), solve(k + 1, j, pref)));
            }
        }
        
        return memo[i][j] = maxScore;
    }

public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        memset(memo, -1, sizeof(memo));
        
        vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + stoneValue[i];
        }
        return solve(0, n - 1, pref);
    }
};
