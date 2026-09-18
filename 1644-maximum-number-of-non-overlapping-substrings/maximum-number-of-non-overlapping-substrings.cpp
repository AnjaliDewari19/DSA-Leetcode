class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int> first(26, -1), last(26, -1);
        for(int i = 0 ; i<n ; ++i){
            int ch = s[i]-'a';
            if(first[ch] == -1){
                first[ch] = i;
            }
            last[ch] = i;
        }

        auto getValidRightBound = [&](int left) -> int{
            int right = last[s[left]-'a'];
            for (int i=left ; i<=right ; ++i){
                int ch = s[i] - 'a';
                if(first[ch] < left){
                    return -1;
                }
                right = max(right, last[ch]);
            }
            return right;
        };

        vector<pair<int,int>> intervals;
        for(int i = 0 ; i<26 ;++i){
            if(first[i] != -1){
                int right = getValidRightBound(first[i]);
                if(right != -1){
                    intervals.push_back({right, first[i]});
                }
            }
        }

        sort(intervals.begin(), intervals.end());
        vector<string> result;
        int prev_end = -1;

        for( auto& [right, left] : intervals){
            if(left > prev_end){
                result.push_back(s.substr(left, right-left + 1));
                prev_end = right;
            }
        }
        return result;
    }
};
