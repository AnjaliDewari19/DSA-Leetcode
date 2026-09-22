class Solution {
public:
    int partition(vector<int> &nums, int low, int high){
        int randomPivot = low + rand() % (high - low + 1);
        swap(nums[randomPivot], nums[high]);

        int pivot = nums[high];
        int i = low - 1;

        for(int j = low ; j <= high-1 ; j++){
            if(nums[j] < pivot){
                i++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i+1], nums[high]);
        return i + 1;
    }

    void quicksort(vector<int> &nums, int low, int high){
        if(low < high){
            int pi = partition(nums, low, high);
            quicksort(nums, low, pi-1);
            quicksort(nums, pi+1 , high);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        srand(time(nullptr));
        quicksort(nums, 0 , nums.size() - 1);
        return nums;
    }
};