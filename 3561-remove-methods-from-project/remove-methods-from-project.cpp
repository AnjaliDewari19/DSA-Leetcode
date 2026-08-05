class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<std::vector<int>> adj(n);
        for (const auto& inv : invocations) {
            adj[inv[0]].push_back(inv[1]);
        }

        vector<bool> isSuspicious(n, false);
        vector<int> queue;
        queue.push_back(k);
        isSuspicious[k] = true;

        int head = 0;
        while (head < queue.size()) {
            int u = queue[head++];
            for (int v : adj[u]) {
                if (!isSuspicious[v]) {
                    isSuspicious[v] = true;
                    queue.push_back(v);
                }
            }
        }

        bool canRemove = true;
        for (const auto& inv : invocations) {
            int u = inv[0], v = inv[1];
            if (!isSuspicious[u] && isSuspicious[v]) {
                canRemove = false;
                break;
            }
        }

        vector<int> result;
        if (!canRemove) {
            for (int i = 0; i < n; ++i) {
                result.push_back(i);
            }
        } else {
            for (int i = 0; i < n; ++i) {
                if (!isSuspicious[i]) {
                    result.push_back(i);
                }
            }
        }
        return result;
    }
};
