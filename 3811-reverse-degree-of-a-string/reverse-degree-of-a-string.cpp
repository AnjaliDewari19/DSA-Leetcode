class Solution {
public:
    int reverseDegree(string s) {
        int total = 0;
        for(int i = 0; i<s.length(); ++i){
            int reverseAlpha = 26 - (s[i] - 'a');
            int stringPos = i + 1;
            total += reverseAlpha * stringPos;
        }

        return total;
    }
};