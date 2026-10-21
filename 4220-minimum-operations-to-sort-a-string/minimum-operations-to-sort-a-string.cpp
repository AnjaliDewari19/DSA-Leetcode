class Solution {
public:
    int minOperations(string s) {
        int n = s.length();

        string sorted_s = s;
        sort(sorted_s.begin(), sorted_s.end());

        if(s == sorted_s) return 0;

        if(n == 2) return -1;
        
        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());

        bool min_at_s = (s[0] == mn);
        bool max_at_e = (s[n-1] == mx);

        if(min_at_s || max_at_e){
            return 1;
        }

        bool mn_in_pre = false;
        for(int i=0 ; i<n-1 ; ++i){
            if(s[i] == mn){
                mn_in_pre = true;
                break;
            }
        }

        bool mx_in_suf = false;
        for(int i=1 ; i<n ; ++i){
            if(s[i] == mx){
                mx_in_suf = true;
                break;
            }
        }

        if(!mn_in_pre && !mx_in_suf){
            return 3;
        }

        return 2;
    }
};