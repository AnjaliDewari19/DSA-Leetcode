class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int count[10] = {0};
        for(int d : digits){
            count[d]++;
        }

        int ans = 0 ;
        for(int n = 100 ; n<1000 ; n+=2 ){
            int req[10] = {0};
            req[n/100]++;
            req[(n/10)%10]++;
            req[n%10]++;

            bool ok = true;
            for(int i=0 ; i<10 ; i++){
                if(req[i] > count[i]){
                    ok = false;
                }
            }
            if(ok) ans++;
        }
        return ans;
    }
};