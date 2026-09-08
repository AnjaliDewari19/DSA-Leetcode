class Solution {
public:
    int countCommas(int n) {
        if(n<999){
            return 0;
        }else{
            int ans = n-999;
            return ans;
        }
    }
};