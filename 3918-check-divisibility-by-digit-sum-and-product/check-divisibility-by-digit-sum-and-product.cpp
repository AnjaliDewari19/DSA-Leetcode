class Solution {
public:
    bool checkDivisibility(int n) {
        bool ans = false;
        long long sum = 0, num = n , pro = 1;
        while(n != 0){
            int digit = n%10 ;
            sum += digit;
            pro *= digit;
            n /= 10;
        }
        if(num%(sum+pro) == 0){
            return true;
        }
        
        return false;
    }
};
