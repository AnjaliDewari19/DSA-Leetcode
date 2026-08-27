class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        vector<int> count = freq;
        int max_match = 0;
        
        while (max_match < n) {
            int idx = target[max_match] - 'a';
            if (count[idx] > 0) {
                count[idx]--;
                max_match++;
            } else {
                break;
            }
        }

        for (int i = max_match; i >= 0; i--) {
            vector<int> cur_freq = freq;
            for (int j = 0; j < i; j++) {
                cur_freq[target[j] - 'a']--;
            }

            if (i < n) {
                int target_char = target[i] - 'a';
                for (int c = target_char + 1; c < 26; c++) {
                    if (cur_freq[c] > 0) {
                        string result = target.substr(0, i);
                        result += (char)('a' + c);
                        cur_freq[c]--;

                        for (int ch = 0; ch < 26; ch++) {
                            while (cur_freq[ch] > 0) {
                                result += (char)('a' + ch);
                                cur_freq[ch]--;
                            }
                        }
                        return result;
                    }
                }
            }
        }
        return "";
    }
};
