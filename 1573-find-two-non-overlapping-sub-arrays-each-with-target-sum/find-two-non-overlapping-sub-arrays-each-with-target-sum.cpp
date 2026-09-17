class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> min_len(n + 1, INT_MAX);
        unordered_map<int, int> prefix_map;
        prefix_map[0] = -1;

        int sum = 0;
        int ans = INT_MAX;
         
        for(int i = 0; i<n ; ++i){
            sum += arr[i];

            min_len[i+1] = min_len[i];

            if(prefix_map.count(sum - target)){
                int left = prefix_map[sum - target];
                int curr_len = i - left;

                if (min_len[left + 1] != INT_MAX){
                    ans = min(ans, min_len[left + 1] + curr_len);
                }

                min_len[i+1] = min(min_len[i+1], curr_len);
            }

            prefix_map[sum] = i;
        }

        return (ans == INT_MAX) ? -1 : ans ;
    }
};