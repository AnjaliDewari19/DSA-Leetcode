class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        for(long long t = 1000; t <= n ; t *= 1000){
            ans += n-t+1;
        }
        return ans;
    }
};