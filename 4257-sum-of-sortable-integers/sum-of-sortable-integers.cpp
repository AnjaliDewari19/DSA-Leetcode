class Solution {
public:     
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int k=1 ; k<=n ; k++){
            if(n%k != 0)
                continue;
            
            bool ok = true;
            int preMax = INT_MIN;

            for(int i=0 ; i<n && ok ; i+=k){
                int mn = nums[i] , mx = nums[i];
                int desc = 0;

                for(int j=i ;j<i+k ; j++){
                    mn = min(mn, nums[j]);
                    mx = max(mx, nums[j]);

                    int next = (j+1 == i+k) ? nums[i] : nums[j+1];

                    if(nums[j] > next)
                        desc++;
                }
                
                if(desc > 1 || preMax > mn)
                    ok = false;

                preMax = mx;
            }

            if(ok)
                ans += k;
        }
        return ans;
    }
};