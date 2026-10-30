class Solution {
public:
    int calPoints(vector<string>& o) {
        stack<int> st;
        int ans = 0, ch, n=o.size();
        for(int i=0 ; i<n ; i++){
            if(o[i] != "C" && o[i] != "D" && o[i] != "+"){
                ch = stoi(o[i]);
                st.push(ch);
            }else if (o[i] == "C"){
                if(!st.empty()){
                    st.pop();
                }
            }else if (o[i] == "+"){
                int a = st.top(), b;
                st.pop();
                b = st.top();
                st.push(a);
                st.push(a+b);
            }else{
                int c = st.top();
                st.push(c*2);
            }
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};