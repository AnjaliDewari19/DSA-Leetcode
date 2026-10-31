class Solution {
public:
    vector<int> intersection(vector<int>& n1, vector<int>& n2) {
        int n = n1.size(), m = n2.size() , i=0, j=0;
        sort(n1.begin(), n1.end());
        sort(n2.begin(), n2.end());

        vector<int> ans;
        while(i<n && j<m){
            if(n1[i] == n2[j] && (ans.empty() || ans.back() != n1[i])){
                ans.push_back(n1[i]);
                i++;
                j++;
            }else if(n1[i] > n2[j]){
                j++;
            }else{
                i++;
            }
        }
        
        return ans;
    }
};