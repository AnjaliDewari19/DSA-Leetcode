class Solution {
public:
    int getDigit(int n){
        int sum = 0;
        while(n>0){
            sum += n%10;
            n /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> arr(n, vector<int>(3));
        for(int i=0 ; i<n ; ++i){
            arr[i][0] = getDigit(nums[i]);
            arr[i][1] = nums[i];
            arr[i][2] = i;
        }

        sort(arr.begin(), arr.end(), [](const vector<int>& a, const vector<int>& b){
            if(a[0] != b[0]) return a[0] < b[0];
            return a[1] < b[1];
        });

        vector<bool> visited(n, false);
        int cycles = 0;
        for(int i=0 ; i<n ; ++i){
            if(visited[i] || arr[i][2] == i){
                continue;
            }
            int j = i;
            int cycle_size = 0;
            while(!visited[j]){
                visited[j] = true;
                j = arr[j][2];
                cycle_size++;
            }
            if(cycle_size > 1){
                cycles += (cycle_size-1);
            }
        }
        return cycles;
    }
};