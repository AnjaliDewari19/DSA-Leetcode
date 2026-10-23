class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int max_k = -1;
        bool mis_found = false;

        for(int i=0 ; i<n ; ++i){
            if(nums[i] != i){
                if(!mis_found){
                    max_k = nums[i];
                    mis_found = true;
                }else{
                    max_k &= nums[i];
                }
            }
        }
        if(!mis_found){
            return 0;
        }

        return max_k;
    }
};