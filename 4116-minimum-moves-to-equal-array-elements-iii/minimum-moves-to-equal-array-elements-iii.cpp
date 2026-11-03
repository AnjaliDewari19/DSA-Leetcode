class Solution {
public:
    int minMoves(vector<int>& nums) {
        int max_val = *max_element(nums.begin(), nums.end());
        int t_move = 0;
        for(int num : nums){
            t_move += (max_val-num);
        }
        return t_move;
    }
};