// class Solution {
// public:
//     int minAddToMakeValid(string s) {
//         int countf=0;
//         int countl=0;
//         // stack<int> st;
//         // for(int i=0;i<s.size;i++){
//         //     st.push(s);
//         //     while(st!=NULL){
//         //         char check=st.top();
//         //         st.pop();
                
//         //     }
//         // }
//         // for(int i=0;i<s.size();i++){
//         //     if(s[i]=='(') countf++;
//         //     else countl++;
//         // }
//         // return abs(countf-countl);
//         for(char c:s){
//             if(c=='(') {countf++;}
//             else if(c==')' && countf>0) {countf--;}
//             else {countl--;}
//         }
// return abs(countf+countl);
//     }
// };
class Solution {
public:
    int minAddToMakeValid(string s) {
        int open_c = 0;
        int close_c = 0;

        for (char c : s) {
            if (c == '(') {
                open_c++;
            } else if (c == ')' && open_c > 0) {
                open_c--;
            } else {
                close_c++;
            }
        }
        return open_c + close_c;
    }
};