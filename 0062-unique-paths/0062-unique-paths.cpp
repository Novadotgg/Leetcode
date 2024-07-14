class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> ans(n,1);
        for(int i=1;i<m;i++){
            vector<int> current(n,1);
            for(int j=1;j<n;j++){
                current[j]=current[j-1]+ans[j];
            }
            ans=current;
        }
        return ans[n-1];
    }
};