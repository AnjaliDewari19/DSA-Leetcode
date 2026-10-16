class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        long long MOD = 1e9 + 7;

        vector<long long> tree(4*n,0);
        vector<long long> lazy(4*n,0);
        vector<long long> sum_val(4*n,0);

        auto push = [&](int node, int l, int r){
            if(lazy[node] != 0){
                int mid = (l+r)/2;
                long long val = lazy[node];

                lazy[2*node] += val;
                tree[2*node] = (tree[2*node] + 2*val*sum_val[2*node] + val*val*(mid-l+1)) % MOD;
                sum_val[2*node] = (sum_val[2*node] + val*(mid-l+1)) % MOD;

                lazy[2*node+1] += val;
                tree[2*node+1] = (tree[2*node+1] + 2*val*sum_val[2*node+1] + val*val*(r-mid)) % MOD;
                sum_val[2*node+1] = (sum_val[2*node+1] + val*(r-mid)) % MOD;

                lazy [node] = 0;
            }
        };

        auto update = [&](auto& self, int node, int l, int r, int ql, int qr, long long val) -> void {
            if(ql>r || qr<l) return ;
            if(ql <= l && r <= qr){
                lazy[node] += val;
                tree[node] = (tree[node] +2*val*sum_val[node] + val*val*(r-l+1)) % MOD;
                sum_val[node] = (sum_val[node] + val*(r-l+1)) % MOD;
                return;
            }
            push(node, l ,r);
            int mid = (l+r) / 2;
            self(self, 2*node, l ,mid, ql ,qr ,val);
            self(self, 2*node+1, mid+1, r, ql, qr, val);
            tree[node] = (tree[2*node] + tree[2*node+1]) % MOD;
            sum_val[node] = (sum_val[2*node] + sum_val[2*node+1]) % MOD;
        };

        unordered_map<int, int> last_seen;
        long long total_sum = 0, cur_ans = 0;

        for(int i=0 ; i<n ; ++i){
            int prev_i = -1;
            if(last_seen.find(nums[i]) != last_seen.end()){
                prev_i = last_seen[nums[i]];
            }
            last_seen[nums[i]] = i;
            update(update , 1, 0, n-1, prev_i+1 , i , 1);
            total_sum = (total_sum + tree[1]) % MOD;
        }

        return total_sum;
    }
};