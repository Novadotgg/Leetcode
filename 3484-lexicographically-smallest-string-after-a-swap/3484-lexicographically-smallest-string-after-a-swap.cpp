class Solution {
public:
    string getSmallestString(string s) {
        // vector<char> digits=(s.begin(),s.end());
        vector<char> digits(s.begin(), s.end());
        int n=s.length();
        for(int i=0;i<n-1;++i){
            if(digits[i]%2==digits[i+1]%2){
                if(digits[i]>digits[i+1]){
                    swap(digits[i],digits[i+1]);
                    break;
                }
            }
        }
        return string(digits.begin(),digits.end());
    }
};