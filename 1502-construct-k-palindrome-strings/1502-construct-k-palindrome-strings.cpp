class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size()<k) return false;
        sort(s.begin(),s.end());
        int oddc=0;
        for(int i=0;i<s.length();){
            char curr=s[i];
            int count=0;
            while(i<s.length() && s[i]==curr){
                count++;
                i++;
            }
            if(count%2!=0)oddc++;
        }
        return oddc<=k;
    }
};

//Bitmasking 
/*
class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.length() < k) return false;

        int bitmask = 0;
        for (char c : s) {
            bitmask ^= (1 << (c - 'a'));
        }

        int oddCount = __builtin_popcount(bitmask);
        return oddCount <= k;
    }
};
*/
