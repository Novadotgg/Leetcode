class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        int ans =0;
        int c=0;
        for(int i =0;i<n;i++){
            if(s[i]=='b')c++;
            else{
                ans=min(ans+1,c);
            }
        }
        return ans;
    }
};