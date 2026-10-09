class Solution {
public:
    int minInsertions(string s) {
        int insertion = 0, openNeed = 0;

        for(int i=0 ; i<s.length() ; i++){
            if(s[i] == '('){
                openNeed++;
            } else {
                if(i+1 < s.length() && s[i+1] == ')'){
                    i++;
                }else{
                    insertion++;
                }

                if(openNeed > 0){
                    openNeed--;
                }else{
                    insertion++;
                }
            }
        }

        insertion += openNeed * 2;
        return insertion;
    }
};