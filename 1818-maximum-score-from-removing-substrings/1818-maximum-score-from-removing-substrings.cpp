class Solution {
private:
    int solve(string& s,string temp){
        int n=s.size();
        int c=0;
        stack<char> st;
        for(int i=0;i<n;i++){
            if(!st.empty() && s[i]==temp[1] && st.top()==temp[0]){
                st.pop();
                c++;
            }
            else{
                st.push(s[i]);
            }
        }
        s="";
        while(!st.empty()){
            s+=st.top();
            st.pop();
        }
        reverse(s.begin(),s.end());
        return c;
    }
public:
    int maximumGain(string s, int x, int y) {
        string l="", h="";
        if(y>x){
            l="ab";
            h="ba";
            swap(x,y);
        }
        else{
            l="ba";
            h="ab";
        }
        int a =solve(s,h)*x;
        int b=solve(s,l)*y;
        return a+b;
    }
};