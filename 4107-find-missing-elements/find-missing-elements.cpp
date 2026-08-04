class Solution {
public:
    vector<int> findMissingElements(vector<int>& v) {
        sort(v.begin(),v.end());
        int n = v.size();
        vector<int> ans;
        // pushing remaining elements between minimun and maximun 
        for(int i=0 ; i<n-1 ;i++){
            for(int cur = v[i]+1 ; cur<v[i+1] ; ++cur){
                ans.push_back(cur);
            }
        }
        return ans;
    }
};
