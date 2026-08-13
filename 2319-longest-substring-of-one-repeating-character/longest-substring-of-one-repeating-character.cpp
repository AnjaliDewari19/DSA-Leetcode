#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Node {
    char lchar, rchar;
    int pref, suff, mx;
};

class Solution {
private:
    vector<Node> tree;

    void merge(Node& parent, const Node& L, const Node& R, int lenL, int lenR) {
        parent.lchar = L.lchar;
        parent.rchar = R.rchar;
        parent.mx = max(L.mx, R.mx);

        // Check cross boundary
        if (L.rchar == R.lchar) {
            parent.mx = max(parent.mx, L.suff + R.pref);
        }

        // Calculate prefix length
        if (L.pref == lenL && L.rchar == R.lchar) {
            parent.pref = lenL + R.pref;
        } else {
            parent.pref = L.pref;
        }

        // Calculate suffix length
        if (R.suff == lenR && L.rchar == R.lchar) {
            parent.suff = lenR + L.suff;
        } else {
            parent.suff = R.suff;
        }
    }

    void build(int node, int start, int end, const string& s) {
        if (start == end) {
            tree[node] = {s[start], s[start], 1, 1, 1};
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid, s);
        build(2 * node + 1, mid + 1, end, s);
        
        int lenL = mid - start + 1;
        int lenR = end - mid;
        merge(tree[node], tree[2 * node], tree[2 * node + 1], lenL, lenR);
    }

    void update(int node, int start, int end, int idx, char ch) {
        if (start == end) {
            tree[node] = {ch, ch, 1, 1, 1};
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, ch);
        } else {
            update(2 * node + 1, mid + 1, end, idx, ch);
        }

        int lenL = mid - start + 1;
        int lenR = end - mid;
        merge(tree[node], tree[2 * node], tree[2 * node + 1], lenL, lenR);
    }

public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.length();
        int k = queryIndices.size();
        tree.resize(4 * n);

        build(1, 0, n - 1, s);

        vector<int> ans(k);
        for (int i = 0; i < k; ++i) {
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            ans[i] = tree[1].mx;
        }

        return ans;
    }
};