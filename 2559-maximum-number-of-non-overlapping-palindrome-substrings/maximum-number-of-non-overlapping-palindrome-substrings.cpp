class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.length(), count = 0, last = -1;

        for(int i=0 ; i<n ; ++i){
            for(int len : {k, k+1}){
                int left = i - len/2, right = i + (len-1)/2;

                if(left > last && right < n && isPalindrome(s, left, right)){
                    count++;
                    last = right;
                    break;
                }
            }
        }
        return count;
    }
    bool isPalindrome(const string& s, int left , int right){
        while(left < right){
            if(s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};