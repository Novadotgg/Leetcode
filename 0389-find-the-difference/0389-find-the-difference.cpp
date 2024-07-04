class Solution {
public:
    char findTheDifference(string s, string t) {
        int x=0;
        for(auto it:s){
            x=x^it;
        }
        for(auto it:t){
            x=x^it;
        }
        return x;
    }
};