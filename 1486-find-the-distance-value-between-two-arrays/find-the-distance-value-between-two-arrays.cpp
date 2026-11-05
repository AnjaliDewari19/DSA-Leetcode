class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int d_value = 0;

        for(int x : arr1){
            bool isValid = true;
            for(int y : arr2){
                if(abs(x-y) <= d){
                    isValid = false;
                    break;
                }
            }

            if (isValid){
                d_value++;
            }
        }

        return d_value;
    }
};