class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<int> ones;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '1') {
                ones.push_back(i);
            }
        }
        if (ones.size() < k) return "";        
        string res = "";
        
        for (int i = 0; i <= ones.size() - k; ++i) {
            int start = ones[i];
            int end = ones[i + k - 1];
            string sub = s.substr(start, end - start + 1);
            
            if (res.empty() || sub.length() < res.length() || 
               (sub.length() == res.length() && sub < res)) {
                res = sub;
            }
        }
        
        return res;
    }
};
