class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<long long>> a(n, vector<long long>(4));
        for(int i=0 ; i<n ; ++i){
            a[i][0] = intervals[i][0];
            a[i][1] = intervals[i][1];
            a[i][2] = intervals[i][2];
            a[i][3] = i;
        }

        sort(a.begin(), a.end(), [](const vector<long long>& x, const vector<long long>& y){
            if (x[1] != y[1])   return x[1] < y[1];
            if (x[2] != y[2])   return x[2] > y[2];
            return x[3] < y[3];
        });

        vector<long long> rights(n);
        for(int i=0 ; i<n ; ++i){
            rights[i] = a[i][1];
        }

        vector<vector<pair<long long, vector<int>>>> dp(n, vector<pair<long long, vector<int>>>(5, {0, {}}));

        for(int i=0 ; i<n ; ++i){
            int idx = -1, low = 0, high = i-1;
            while(low <= high){
                int mid = low + (high-low)/2;
                if(a[mid][1] < a[i][0]){
                    idx = mid;
                    low = mid+1;
                }else{
                    high = mid-1;
                }
            }
            for (int j = 1; j<= 4; ++j){
                dp[i][j] = (i>0) ? dp[i-1][j] : make_pair(0LL, vector<int>());

                long long prev_weight = 0;
                vector<int> prev_indices;
                if(idx != -1 && j > 1){
                    prev_weight = dp[idx][j-1].first;
                    prev_indices = dp[idx][j - 1].second;
                } else if (j > 1) {
                    continue; // Cannot form j intervals if no valid previous interval exists
                }

                long long cur_weight = prev_weight + a[i][2];
                vector<int> cur_indices = prev_indices;
                cur_indices.push_back(a[i][3]);
                sort(cur_indices.begin(), cur_indices.end());

                // Compare with existing dp[i][j] to maximize weight and keep lexicographically smallest indices
                if (i > 0) {
                    if (cur_weight > dp[i - 1][j].first) {
                        dp[i][j] = {cur_weight, cur_indices};
                    } else if (cur_weight == dp[i - 1][j].first && !dp[i - 1][j].second.empty() && cur_indices < dp[i - 1][j].second) {
                        dp[i][j] = {cur_weight, cur_indices};
                    }
                } else {
                    dp[i][j] = {cur_weight, cur_indices};
                }
            }
        }

        // Find the best answer across all counts from 1 to 4
        pair<long long, vector<int>> best = {0, {}};
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j <= 4; ++j) {
                if (dp[i][j].first > best.first) {
                    best = dp[i][j];
                } else if (dp[i][j].first == best.first && !dp[i][j].second.empty()) {
                    if (best.second.empty() || dp[i][j].second < best.second) {
                        best = dp[i][j];
                    }
                }
            }
        }
        return best.second;
    }
};
              
