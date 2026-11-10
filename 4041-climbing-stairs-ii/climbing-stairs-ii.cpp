class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<long long> dp(n+1, 0);

        dp[0] = 0;
        for(int j=1 ; j<=n ; ++j){
            long long min_cost = -1;
            for(int k=1 ; k<=3 ; ++k){
                int i = j-k ;
                if(i >= 0){
                    long long cur_cost = dp[i] + costs[j-1] + (long long)(j-i)*(j-i);
                    if(min_cost == -1 || cur_cost < min_cost){
                        min_cost = cur_cost;
                    }
                }
            }
            dp[j] = min_cost;
        }
        return dp[n];
    }
};