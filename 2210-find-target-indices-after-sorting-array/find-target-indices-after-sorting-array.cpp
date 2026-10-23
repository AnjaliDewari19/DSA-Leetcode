class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int countLessThan = 0 , countEqual = 0;

        for(int num : nums){
            if(num < target){
                countLessThan++;
            }else if(num == target){
                countEqual++;
            }
        }

        vector<int> result;
        for(int i=0 ; i<countEqual ; ++i){
            result.push_back(countLessThan+i);
        }

        return result;
    }
};