#include <vector>
class Solution {
public:
    std::vector<long long> resultArray(std::vector<int>& nums, int k) {
        std::vector<long long> result(k,0);
        std::vector<long long>dp(k,0);

        for(int num : nums){
            std::vector<long long> next_dp(k,0);
            int val_mod = ((num % k)+k)%k;

            next_dp[val_mod]++;

            for(int r=0 ; r<k ; ++r){
                if(dp[r] > 0){
                    int new_mod = (r * val_mod) % k;
                    next_dp[new_mod] += dp[r];
                }
            }

            dp = std::move(next_dp);

            for(int r=0 ; r<k ; ++r){
                result[r] += dp[r];
            }
        }
        return result;
    }
};