class Solution {
public:
    int countSeniors(vector<string>& details) {
        int c = 0;
        for (int i = 0; i < details.size(); i++) {
            int age = (details[i][11] - '0') * 10 + (details[i][12] - '0');
            if (age > 60) c += 1;
        }
        return c;
    }
};