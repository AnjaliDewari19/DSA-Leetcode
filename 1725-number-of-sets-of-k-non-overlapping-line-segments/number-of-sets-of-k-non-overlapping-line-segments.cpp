class Solution {
    int MOD = 1e9 + 7;

    long long power(long long base, long long exp){
        long long res = 1;
        base %= MOD;
        while (exp > 0){
            if (exp % 2 == 1) res = (res*base)%MOD;
            base = (base*base)%MOD;
            exp /= 2;
        }
        return res;
    }

public:
    int numberOfSets(int n, int k) {
        long long N = n+k-1, K = 2*k, num = 1, den = 1;
        for(int i=0 ; i<K ; i++){
            num = (num * (N-i)) % MOD;
            den = (den * (i+1)) % MOD;
        }
        return (num * power(den, MOD-2)) % MOD;
    }
};
