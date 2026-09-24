class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i=0 ; i<n ; i++){
            int sum = 0, temp = nums[i];
            while(temp > 0){
                sum += temp%10;
                temp /= 10;
            }   

            if(nums[i] == 0){
                sum = 0;
            }

            if(sum == i){
                return i;
            }
        }
        return -1;
    }
};