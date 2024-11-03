class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;

        return (s+s).find(goal)!=string::npos;
        //string::npos is a constant in C++ that indicates "not found"
        //Since s+s contains all the possible rotations of a string
    }
};