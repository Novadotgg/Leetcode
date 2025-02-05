class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int a=-1;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                if(a==-1) a=i;
                else{
                    swap(s1[i],s1[a]);
                    return s1==s2;
                }
            }
        }  
        return s1==s2;
    }
};