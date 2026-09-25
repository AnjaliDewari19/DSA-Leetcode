class Solution {
public:
    set<string> combine(set<string> a, set<string> b){
        set<string> ans;
        for(string x : a){
            for(string y : b){
                ans.insert(x+y);
            }
        }
        return ans;
    }

    set<string> solve(string &s , int &i){
        set<string> result;
        set<string> current = {""};
        while(i < s.size() && s[i] != '}'){
            if (s[i] == ','){
                // union
                result.insert(current.begin(), current.end());
                current.clear();
                current.insert("");
                i++;
            }else if(s[i] == '{'){
                i++; // skip {
                set<string> inside = solve(s, i);
                i++; // skip }
                current = combine(current, inside);
            }else{
                set<string> letter;
                letter.insert(string(1, s[i]));
                current = combine(current, letter);
                i++;
            }
        }
        result.insert(current.begin(), current.end());
        return result;
    }

    vector<string> braceExpansionII(string expression) {
        int i=0;
        set<string> ans = solve(expression, i);
        return vector<string>(ans.begin(), ans.end());
    }
};