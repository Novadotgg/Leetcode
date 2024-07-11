class Solution {
public:
    string reverseParentheses(string s) {
        int i = 0;
        stack<char> st;
        vector<char> ans;
        int n = s.size();
        
        while (i < n) {
            if (s[i] == '(') {
                st.push(s[i]);
                i++;
            } else if (s[i] == ')') {
                string temp;
                while (!st.empty() && st.top() != '(') {
                    temp += st.top();
                    st.pop();
                }
                if (!st.empty() && st.top() == '(') {
                    st.pop(); 
                }
                for (char c : temp) {
                    st.push(c); 
                }
                i++;
            } else {
                st.push(s[i]);
                i++;
            }
        }
        
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end()); 
        return string(ans.begin(), ans.end());
    }
};