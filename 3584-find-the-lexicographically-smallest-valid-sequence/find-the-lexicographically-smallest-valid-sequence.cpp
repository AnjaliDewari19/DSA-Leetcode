class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        // last[j] stores the rightmost index in word1 that matches word2[j...m-1]
        vector<int> last(m, -1);
        int j = m - 1;
        for (int i = n - 1; i >= 0 && j >= 0; i--) {
            if (word1[i] == word2[j]) {
                last[j] = i;
                j--;
            }
        }

        vector<int> ans;
        bool changed = false;
        j = 0;

        for (int i = 0; i < n && j < m; i++) {
            // Case 1: Exact match
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            } 
            // Case 2: Mismatch, try to use the allowed character replacement
            else if (!changed && (j == m - 1 || last[j + 1] > i)) {
                ans.push_back(i);
                changed = true;
                j++;
            }
        }

        return (ans.size() == m) ? ans : std::vector<int>();
    }
};
