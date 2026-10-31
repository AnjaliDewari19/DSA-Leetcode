class Solution {
public:
    int missingNumber(vector<int>& n) {
      sort(n.begin(), n.end());
      int mis_no, found = 0;

      if(n[0] != 0){
        return 0;
      }

      for(int i=0 ; i<n.size()-1 ; i++){
        if(n[i]+1 != n[i+1]){
            found = 1;
            mis_no = n[i]+1;
            }
        }

        if(found == 0){
            mis_no = n.back()+1;
            return mis_no;
        }

        return mis_no;
    }
};