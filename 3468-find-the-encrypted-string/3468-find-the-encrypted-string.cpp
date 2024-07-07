class Solution {
public:
    string getEncryptedString(string s, int k) {
        // for(int i=0;i<s.size();i++){
        //     if(i+k<s.size()){
        //         swap(s[i],s[i+k]);
        //     }
        // }
        // return s;
        int n=s.size();
        string ans;
        k=k%n;
        for(int i=k;i<n;i++){
            ans+=s[i];
        }
        for(int i=0;i<k;i++){
            ans+=s[i];
        }
        return ans;
    }
};

