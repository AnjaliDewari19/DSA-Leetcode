class Solution {
public:
    int missingInteger(vector<int>& n) {
        int s = n.size() , sum = n[0];
        for(int i=1 ; i<s ; ++i){
            if(n[i] == n[i-1]+1){
                sum += n[i];
            }else{
                break;
            }
        } 
        unordered_set<int> numSet(n.begin(), n.end());
        while(numSet.count(sum)){
            sum++;
        }
        return sum;
    }
};
