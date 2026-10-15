class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> bitCount(32, 0);

        for(int num : nums){
            for(int i=0 ; i<32 ; ++i){
                if((num >> i) & 1){
                    bitCount[i]++;
                }
            }
        }

        long long total = 0, mod = 1e9 + 7;

        for(int step = 0; step<k ; ++step){
            long long currentNum = 0;
            for(int i=0 ; i<32 ; ++i){
                if (bitCount[i] > 0){
                    currentNum |= (1LL << i);
                    bitCount[i]--;
                }
            }
            total = (total + currentNum * currentNum) % mod;
        }
        
        return total;
    }
};
