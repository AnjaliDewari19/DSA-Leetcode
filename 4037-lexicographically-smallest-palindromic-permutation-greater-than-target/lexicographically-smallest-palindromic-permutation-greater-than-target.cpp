class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        int odd_count = 0;
        int odd_char = -1;
        for (int i = 0; i < 26; ++i) {
            if (count[i] % 2 != 0) {
                odd_count++;
                odd_char = i;
            }
        }

        if (odd_count > 1) return "";

        vector<int> half_count(26, 0);
        for (int i = 0; i < 26; ++i) {
            half_count[i] = count[i] / 2;
        }

        int half_len = n / 2;
        string best = "";

        auto construct_full = [&](const string& half_str) {
            string res = half_str;
            if (n % 2 != 0) {
                res += (char)('a' + odd_char);
            }
            string rev = half_str;
            reverse(rev.begin(), rev.end());
            res += rev;
            return res;
        };

        bool can_match_exact = true;
        vector<int> temp_count = half_count;
        string exact_half = "";

        for (int i = 0; i < half_len; ++i) {
            int t_char = target[i] - 'a';
            if (temp_count[t_char] > 0) {
                temp_count[t_char]--;
                exact_half += target[i];
            } else {
                can_match_exact = false;
                break;
            }
        }

        if (can_match_exact) {
            string cand = construct_full(exact_half);
            if (cand > target) {
                best = cand;
            }
        }

        vector<int> curr_count = half_count;
        string curr_prefix = "";

        for (int i = 0; i < half_len; ++i) {
            int target_char = target[i] - 'a';

            for (int c = target_char + 1; c < 26; ++c) {
                if (curr_count[c] > 0) {
                    string half_str = curr_prefix + (char)('a' + c);
                    vector<int> rem_count = curr_count;
                    rem_count[c]--;

                    for (int ch = 0; ch < 26; ++ch) {
                        half_str.append(rem_count[ch], 'a' + ch);
                    }

                    string cand = construct_full(half_str);
                    if (best == "" || cand < best) {
                        best = cand;
                    }
                }
            }

            if (curr_count[target_char] > 0) {
                curr_count[target_char]--;
                curr_prefix += target[i];
            } else {
                break;
            }
        }

        return best;
    }
};