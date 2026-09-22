class Solution {
public:
    int K;
    struct Node {
        int full[5];
        int cnt[5][5];
    };
    vector<Node> tree;
    int n;

    Node makeLeaf(long long val) {
        Node nd;
        int v = (int)(val % K);
        for (int r = 0; r < K; r++) {
            int f = (r * v) % K;
            nd.full[r] = f;
            for (int x = 0; x < K; x++) nd.cnt[r][x] = (x == f) ? 1 : 0;
        }
        return nd;
    }

    Node combine(const Node& L, const Node& R) {
        Node res;
        for (int r = 0; r < K; r++) {
            int mid = L.full[r];
            res.full[r] = R.full[mid];
            for (int x = 0; x < K; x++) {
                res.cnt[r][x] = L.cnt[r][x] + R.cnt[mid][x];
            }
        }
        return res;
    }

    void build(int node, int l, int r, vector<int>& nums) {
        if (l == r) {
            tree[node] = makeLeaf(nums[l]);
            return;
        }
        int mid = (l + r) / 2;
        build(2*node, l, mid, nums);
        build(2*node+1, mid+1, r, nums);
        tree[node] = combine(tree[2*node], tree[2*node+1]);
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            tree[node] = makeLeaf(val);
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid) update(2*node, l, mid, idx, val);
        else update(2*node+1, mid+1, r, idx, val);
        tree[node] = combine(tree[2*node], tree[2*node+1]);
    }

    Node query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) / 2;
        if (qr <= mid) return query(2*node, l, mid, ql, qr);
        if (ql > mid) return query(2*node+1, mid+1, r, ql, qr);
        Node left = query(2*node, l, mid, ql, qr);
        Node right = query(2*node+1, mid+1, r, ql, qr);
        return combine(left, right);
    }

    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        K = k;
        n = (int)nums.size();
        tree.assign(4 * n, Node());
        build(1, 0, n - 1, nums);

        vector<int> result;
        result.reserve(queries.size());
        int r0 = 1 % K;

        for (auto& q : queries) {
            int index = q[0], value = q[1], start = q[2], x = q[3];
            update(1, 0, n - 1, index, value);
            Node res = query(1, 0, n - 1, start, n - 1);
            result.push_back(res.cnt[r0][x]);
        }
        return result;
    }
};