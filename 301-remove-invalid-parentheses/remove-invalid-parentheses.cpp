class Solution {
public:
    unordered_set<string> resultSet;
    void solve(const string& s, int index, int openCount, int closeCount, int invalidOpen, int invalidClose, string& current){
        if(index == s.length()){
            if(invalidOpen == 0 && invalidClose == 0 && openCount == closeCount){
                resultSet.insert(current);
            }
            return ;
        }

        char ch = s[index];

        if(ch == '(' && invalidOpen > 0){
            solve(s, index+1, openCount, closeCount, invalidOpen-1, invalidClose, current);
        }else if (ch == ')' && invalidClose > 0){
            solve(s, index+1, openCount, closeCount, invalidOpen, invalidClose-1, current);
        }

        current.push_back(ch);

        if(ch != '(' && ch != ')'){
            solve(s, index+1, openCount, closeCount, invalidOpen, invalidClose, current);
        }else if(ch == '('){
            solve(s, index+1 , openCount+1, closeCount, invalidOpen, invalidClose, current);
        }else if(ch == ')' && openCount > closeCount){
            solve(s, index+1, openCount, closeCount+1, invalidOpen, invalidClose, current);
        }
        
        current.pop_back();
    }

    vector<string> removeInvalidParentheses(string s) {
        int invalidOpen = 0 , invalidClose = 0;

        for(char ch : s){
            if(ch == '('){
                invalidOpen++;
            }else if(ch == ')'){
                if (invalidOpen > 0){
                    invalidOpen--;
                }else{
                    invalidClose++;
                }
            }
        }
        
        string current = "";
        solve(s, 0,0,0 ,invalidOpen, invalidClose, current);

        return vector<string>(resultSet.begin(), resultSet.end());
    }
};
