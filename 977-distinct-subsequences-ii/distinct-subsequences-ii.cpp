class Solution {
public:
    int distinctSubseqII(string s) {
        vector<long> ends_with(26,0);
        int mod = 1e9 + 7;

        for(char c : s){
            long total = 0;
            for(int count : ends_with){
                total = (total + count) % mod;
            }
            ends_with[c - 'a'] = (total+1) % mod;
        }
        long result = 0;
        for(int count : ends_with){
            result = (result + count) % mod;
        }
        return result;
    }
};
