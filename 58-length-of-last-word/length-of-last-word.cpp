class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        int i = s.size() - 1;

        // 1. Skip trailing spaces at the end
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        // 2. Count length of the last word
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }

        return length;
    }
};