class Solution {
public:
    int maxDepth(string s) {
        int cur_depth = 0, max_depth = 0;
        for(char c : s){
            if(c == '('){
                cur_depth++;
                if(cur_depth > max_depth){
                    max_depth = cur_depth;
                }
            }else if(c == ')'){
                cur_depth--;
            }
        }
        
        return max_depth;
    }
};
