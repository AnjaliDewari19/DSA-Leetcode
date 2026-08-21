class Solution {
public:
    long long gcd(long long a, long long b) {
        return gcd(a, b);
    }

    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }

    long long countAmounts(long long x, const vector<int>& coins) {
        int n = coins.size();
        long long count = 0;

        // Iterate through all subsets using bitmasking
        for (int mask = 1; mask < (1 << n); ++mask) {
            long long current_lcm = 1;
            int bit_count = 0;
            bool overflow = false;

            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    bit_count++;
                    current_lcm = lcm(current_lcm, coins[i]);
                    if (current_lcm > x) {
                        overflow = true;
                        break;
                    }
                }
            }

            if (overflow) continue;

            if (bit_count % 2 == 1) {
                count += x / current_lcm;
            } else {
                count -= x / current_lcm;
            }
        }

        return count;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        long long low = 1;
        long long min_coin = *min_element(coins.begin(), coins.end());
        long long high = min_coin * k;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (countAmounts(mid, coins) >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
