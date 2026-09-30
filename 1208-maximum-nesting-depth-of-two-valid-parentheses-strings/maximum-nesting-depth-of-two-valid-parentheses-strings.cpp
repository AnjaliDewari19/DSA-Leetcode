class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans(seq.length());
        for(int i=0 ; i<seq.length() ; ++i){
            ans[i] = (i%2) ^ (seq[i] == '(' ? 1 : 0);
        }
        
        return ans;
    }
};
