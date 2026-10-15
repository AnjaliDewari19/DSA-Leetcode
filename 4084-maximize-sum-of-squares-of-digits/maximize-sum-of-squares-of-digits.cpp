class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        long long max_possible_sum = 9LL * num;
        if(sum > max_possible_sum || sum<1 && num>1){
            return "";
        }

        string result = "";
        for (int i=0 ; i<num ; ++i){
            int rem_slots = num-1-i;
            int min_d = max(0, sum-9*rem_slots);
            int max_d = min(9, sum);
            int d = max_d;

            result += to_string(d);
            sum -= d;
        }

        if(sum != 0) return "";
        
        return result;
    }
};
